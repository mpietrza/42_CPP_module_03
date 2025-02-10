/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:55:28 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/10 17:35:58 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <climits>
#include <cstdlib>

// ANSI escape codes for text formatting
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string DIM = "\033[2m";
const std::string RED = "\033[31m";
const std::string GRN = "\033[32m";
const std::string YLW = "\033[33m";
const std::string BLU = "\033[34m";
const std::string MGT = "\033[35m";
const std::string CYN = "\033[36m";
const std::string WHT = "\033[37m";
const std::string BOLD_YLW = "\033[1;33m";

void printStatus(ClapTrap &player)
{
	std::string	target;
	if (player.getName() == "Clap")
		target = "Trap";
	else
		target = "Clap";
	std::cout << BOLD << "Name: " << player.getName() << RESET << std::endl;
	std::cout << GRN << "Hit points" << RESET << ": " << player.getHitPoints() << std::endl;
	std::cout << RED << "Energy points" << RESET << ": " << player.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: "<< GRN <<"hit points " << RESET << target << " will lose: " << player.getAttackDamage() << std::endl;
	std::cout << "Repair points: " << GRN << "hit points " << RESET << player.getName() << " gets back each repair: " << player.getRepairPoints() << std::endl;
	std::cout << std::endl;
}

int getValidIntegerInput(const std::string& prompt) 
{
	std::string input;
	int value;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			exit(0);
		}
		try 
		{
			value = atoi(input.c_str());
			if (value < 0 || value > INT_MAX) 
			{
				throw std::out_of_range("Input out of range");
			}
			break;
		}
		catch (const std::out_of_range&)
		{
			std::cout << RED << "Input out of range. Please enter a valid non-negative integer." << RESET << std::endl;
		}
		catch (const std::invalid_argument&)
		{
			std::cout << RED << "Invalid input. Please enter a valid non-negative integer." << RESET << std::endl;
		}
	}
	return value;
}

void actions(ClapTrap &player, ClapTrap &target)
{
	std::string	input;
	std::cout << "Choose action for " << player.getName() << ": 'a' to attack, 'r' to repair" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		target.takeDamage(player.getAttackDamage());
	}
	else if (input == "r")
		player.beRepaired(player.getRepairPoints());
	else
		std::cout << RED <<"Invalid input, please try again." << RESET << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	std::string	input;
	std::cout << BOLD << "Welcome to the ClapTrap game!" << RESET << std::endl;
	std::cout << "Clap and Trap will fight until one of them dies." << std::endl;
	std::cout << "Clap has 10 " << GRN << "hit points" << RESET << " and 10 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "Trap has 10 " << GRN << "hit points" << RESET << " and 10 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "Attacking and repairing cost 1 " << RED << "energy point" << RESET << " each." << std::endl;
	std::cout << std::endl;
	std::cout << "Please type how many " << GRN << "hit points" << RESET << " of damage each attack will cause." << std::endl;

	int clapAttackDamage = getValidIntegerInput("Clap's attack damage: \033[32mhit points\033[0m Trap will lose when attacked: ");
	int trapAttackDamage = getValidIntegerInput("Trap's attack damage: \033[32mhit points\033[0m Clap will lose when attacked: ");
	clap.setAttackDamage(clapAttackDamage);
	trap.setAttackDamage(trapAttackDamage);
	std::cout << std::endl;
	std::cout << "Please type how many \033[32mhit points\033[0m each repair will give back." << std::endl;
	int clapRepairPoints = getValidIntegerInput("Clap's amount of \033[32hit points\033[0m each time it repairs: ");
	int trapRepairPoints = getValidIntegerInput("Trap's amount of \033[32hit points\033[0m each time it repairs: ");
	clap.setRepairPoints(clapRepairPoints);
	trap.setRepairPoints(trapRepairPoints);
	std::cout << std::endl;


	while (clap.getHitPoints() > 0 && trap.getHitPoints() > 0)
	{
		std::cout << "Choose player:" << std::endl;
		std::cout << "type 'c' for Clap and 't' for Trap" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			exit(0);
		}
		else if (input == "c")
			actions(clap, trap);
		else if (input == "t")
			actions(trap, clap);
		else
		{
			std::cout << RED << "Invalid input, please try again." << RESET << std::endl;
			continue;
		}
		printStatus(clap);
		printStatus(trap);
		if (clap.getHitPoints() <=0)
			std::cout << BOLD_YLW << "Trap wins!" << RESET << std::endl;
		if (trap.getHitPoints() <=0)
			std::cout << BOLD_YLW << "Clap wins!" << RESET << std::endl;
		
	}
	return (0);
}
