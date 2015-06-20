library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--use work.cpu_constant_library.all;

entity control_unit is
  port (
    instr_op          : in std_logic_vector(5 downto 0);
    reg_dst           : out std_logic;
    branch            : out std_logic;
    mem_read          : out std_logic;
    mem_to_reg        : out std_logic;
    alu_op            : out std_logic_vector(1 downto 0);
    mem_write         : out std_logic;
    alu_src           : out std_logic;
    reg_write         : out std_logic
    );
end control_unit;

architecture Behavioral of control_unit is

begin
process( instr_op)
begin
	if (instr_op = "000000") then
		reg_dst <= '1';
		branch <= '0';
		mem_read <= '0';
		mem_to_reg <= '0';
		alu_op <= "10";
		mem_write <= '0';
		alu_src <= '0';
		reg_write <= '1';
	elsif (instr_op = "100011") then
		reg_dst <= '0';
		branch <= '0';
		mem_read <= '1';
		mem_to_reg <= '1';
		alu_op <= "00";
		mem_write <= '0';
		alu_src <= '1';
		reg_write <= '1';
	elsif (instr_op = "101011") then
		branch <= '0';
		mem_read <= '0';
		alu_op <= "00";
		mem_write <= '1';
		alu_src <= '1';
		reg_write <= '0';
	elsif (instr_op = "000100") then
		branch <= '1';
		mem_read <= '0';
		alu_op <= "01";
		mem_write <= '0';
		alu_src <= '0';
		reg_write <= '0';
	elsif (instr_op = "001000") then
		reg_dst <= '1';
		branch <= '0';
		mem_read <= '0';
		mem_to_reg <= '0';
		alu_op <= "10";
		mem_write <= '0';
		alu_src <= '1';
		reg_write <= '1';
	elsif (instr_op = "100111") then
		reg_dst <= '1';
		branch <= '0';
		mem_read <= '0';
		mem_to_reg <= '0';
		alu_op <= "10";
		mem_write <= '0';
		alu_src <= '0';
		reg_write <= '1';

	end if;
		
end process;
end Behavioral;
