--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:14:54 11/08/2013
-- Design Name:   
-- Module Name:   /home/csmajs/mcole004/control_unit/alu_control_tb.vhd
-- Project Name:  control_unit
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu_control
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY alu_control_tb IS
END alu_control_tb;
 
ARCHITECTURE behavior OF alu_control_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu_control
    PORT(
         alu_op : IN  std_logic_vector(1 downto 0);
         instruction_5_0 : IN  std_logic_vector(5 downto 0);
         alu_out : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal alu_op : std_logic_vector(1 downto 0) := (others => '0');
   signal instruction_5_0 : std_logic_vector(5 downto 0) := (others => '0');

 	--Outputs
   signal alu_out : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace clk below with 
   -- appropriate port name 
	signal clk :std_logic;
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu_control PORT MAP (
          alu_op => alu_op,
          instruction_5_0 => instruction_5_0,
          alu_out => alu_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      alu_op <= "00";
		instruction_5_0 <= "100010";
		
		wait for 100 ns;	
      alu_op <= "01";
		instruction_5_0 <= "100100";
		
		wait for 100 ns;	
      alu_op <= "10";
		instruction_5_0 <= "100000";
		
		wait for 100 ns;	
      alu_op <= "11";
		instruction_5_0 <= "100010";
		
		wait for 100 ns;	
      alu_op <= "11";
		instruction_5_0 <= "100100";
		
		wait for 100 ns;	
      alu_op <= "10";
		instruction_5_0 <= "100101";
		
		wait for 100 ns;	
      alu_op <= "10";
		instruction_5_0 <= "101010";
		
      wait;
   end process;

END;
