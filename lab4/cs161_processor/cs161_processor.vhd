library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.numeric_std.all;
use work.cpu_component_library.all;



entity cs161_processor is
  port (
    clk            : in std_logic;
    rst            : in std_logic;
	 
    -- Debug Signals
    prog_count     : out std_logic_vector(31 downto 0);
    instr_opcode   : out std_logic_vector(5 downto 0);
    reg1_addr      : out std_logic_vector(4 downto 0);
    reg1_data      : out std_logic_vector(31 downto 0);
    reg2_addr      : out std_logic_vector(4 downto 0);
    reg2_data      : out std_logic_vector(31 downto 0);
    write_reg_addr : out std_logic_vector(4 downto 0);
    write_reg_data : out std_logic_vector(31 downto 0)
    );
end cs161_processor;

architecture Behavioral of cs161_processor is
signal mux_to_pc : std_logic_vector(31 downto 0);
signal pc_to_mem : std_logic_vector(31 downto 0);
signal instruction : std_logic_vector(31 downto 0);
signal pc_plus_four : std_logic_vector(31 downto 0);
signal control_reg_dst : std_logic;
signal control_branch : std_logic;
signal control_mem_read : std_logic;
signal control_mem_to_reg : std_logic;
signal control_ALU_op : std_logic_vector(1 downto 0);
signal control_mem_write : std_logic;
signal control_ALU_src : std_logic;
signal control_reg_write : std_logic;
signal mux_to_writereg : std_logic_vector(4 downto 0);
signal reg_read_data1 : std_logic_vector(31 downto 0);
signal reg_read_data2 : std_logic_vector(31 downto 0);
signal data_to_reg : std_logic_vector(31 downto 0);
signal ALUcontrol_to_ALU : std_logic_vector(3 downto 0);
signal mux_to_ALU : std_logic_vector(31 downto 0);
signal sign_extend : std_logic_vector(31 downto 0);
signal ALU_zero : std_logic;
signal ALU_result : std_logic_vector(31 downto 0);
signal mem_data_out : std_logic_vector(31 downto 0);
signal shift_left2 : std_logic_vector(31 downto 0);
signal PC_mux_select : std_logic;
signal added_shift : std_logic_vector(31 downto 0);

begin
	prog_count <= mux_to_pc;
   instr_opcode <= instruction(31 downto 26);
   reg1_addr <= instruction(25 downto 21);
   reg1_data <= reg_read_data1;
   reg2_addr <= instruction(20 downto 16);
   reg2_data <= reg_read_data2;
   write_reg_addr <= mux_to_writereg;
   write_reg_data <= mem_data_out;
	
	PC : generic_register
	generic Map(SIZE => 32)
	Port Map( 	clk => clk,
					rst => rst,
					write_en => '1',
					data_in => mux_to_pc,
					data_out => pc_to_mem );
	
	pc_plus_four <= pc_to_mem + 4;
	sign_extend <= SXT(instruction(15 downto 0), 32);
	
	IMem : memory
	generic Map(COE_FILE_NAME => "init.coe")
	Port Map(	--clk => clk,
					rst => rst,
					instr_read_address => pc_to_mem(9 downto 2),
					instr_instruction => instruction,
					data_mem_write => control_mem_write,
					data_address => ALU_result(9 downto 2),
					data_write_data => reg_read_data2,     
					data_read_data => mem_data_out);
					
	Register_Mux : mux_2_1
	generic Map(SIZE => 5)
	Port Map(	--clk => clk,
					--rst => rst,
					select_in => control_reg_dst,
					data_0_in => instruction(20 downto 16),
					data_1_in => instruction(15 downto 11),
					data_out => mux_to_writereg );
					
	C_unit : control_unit
	Port Map( 	instr_op => instruction(31 downto 26),
					reg_dst => control_reg_dst,
					branch => control_branch,
					mem_read => control_mem_read,
					mem_to_reg => control_mem_to_reg,
					alu_op => control_ALU_op,
					mem_write => control_mem_write,
					alu_src => control_ALU_src,
					reg_write => control_reg_write );
	
	registers : cpu_registers
	Port Map(	rst => rst,
					reg_write => control_reg_write,
					read_register_1 => instruction(25 downto 21),
					read_register_2 => instruction(20 downto 16),
					write_register => mux_to_writereg,
					write_data => data_to_reg,
					read_data_1 => reg_read_data1,    
					read_data_2 => reg_read_data2);
					 
	ALU_c : alu_control
	Port Map(	alu_op => control_ALU_op,
					instruction_5_0 => instruction(5 downto 0),
					alu_out => ALUcontrol_to_ALU);
	
	
	
	ALU_Mux : mux_2_1
	generic Map(SIZE => 32)
	Port Map(	--clk => clk,
					--rst => rst,
					select_in => control_ALU_src,
					data_0_in => reg_read_data2,
					data_1_in => sign_extend,
					data_out => mux_to_ALU );
					
	ALU_F : alu
	Port Map(	alu_control_in => ALUcontrol_to_ALU,
					channel_a_in => reg_read_data1,
					channel_b_in => mux_to_ALU,
					zero_out => ALU_zero,
					alu_result_out => ALU_result);
	
	Data_Mux : mux_2_1
	generic Map(SIZE => 32)
	Port Map(	--clk => clk,
					--rst => rst,
					select_in => control_mem_to_reg,
					data_0_in => ALU_result,
					data_1_in => mem_data_out,
					data_out => data_to_reg);
	
	pc_mux_select <= control_branch and ALU_zero;
	shift_left2 <= sign_extend(29 downto 0) & "00";
	added_shift <= shift_left2 + pc_plus_four;
	
	PC_Mux : mux_2_1
	generic Map(SIZE => 32)
	Port Map(	--clk => clk,
					--rst => rst,
					select_in => PC_mux_select,
					data_0_in => pc_plus_four,
					data_1_in => added_shift,
					data_out => mux_to_pc);



end Behavioral;

