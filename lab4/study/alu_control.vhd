library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--use work.cpu_constant_library.all;

entity alu_control is
  port (
    alu_op            : in std_logic_vector(1 downto 0);
    instruction_5_0   : in std_logic_vector(5 downto 0);
    alu_out           : out std_logic_vector(3 downto 0)
    );
end alu_control;

architecture Behavioral of alu_control is

begin
process(alu_op, instruction_5_0)
begin
	if (alu_op = "00") then
		alu_out <= "0010";
	elsif (alu_op = "01") then
		alu_out <= "0110";
	else 
		if (instruction_5_0(3 downto 0) = "0000") then
			alu_out <= "0010";
		elsif (instruction_5_0(3 downto 0) = "0010") then
			alu_out <= "0110";
		elsif (instruction_5_0(3 downto 0) = "0100") then
			alu_out <= "0000";
		elsif (instruction_5_0(3 downto 0) = "0101") then
			alu_out <= "0001";
		elsif (instruction_5_0(3 downto 0) = "1010") then 
			alu_out <= "0111";
		elsif (instruction_5_0(3 downto 0) = "0111") then
			alu_out <= "1100";
		else
			alu_out <= "1111";
		end if;
	end if;
	
end process;

end Behavioral;
