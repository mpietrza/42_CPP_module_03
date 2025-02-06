/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:55:28 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/06 16:10:29 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <stdexcept>
#include <climits>

int getValidIntegerInput(const std::string& prompt) 
{
	std::string input;
	int value;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof() == true) {
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			std::exit(0);
		}
		try {
			value = std::stoi(input);
			if (value < 0 || value > INT_MAX) {
				throw std::out_of_range("Input out of range");
			}
			break;
		} catch (const std::out_of_range&) {
			std::cout << RED << "Input out of range. Please enter a valid non-negative integer." << RESET << std::endl;
		} catch (const std::invalid_argument&) {
			std::cout << RED << "Invalid input. Please enter a valid non-negative integer." << RESET << std::endl;
		}
	}
	return value;
}

void actionsClapTrap(ClapTrap &player, ScavTrap &target)
{
	std::string	input;
	std::cout << "Choose action for ClapTrap: 'a' to attack, 'r' to repair" << std::endl;
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

void actionsScavTrap(ScavTrap &player, ClapTrap &target)
{
	std::string	input;
	std::cout << "Choose action for ScavTrap: 'a' to attack, 'r' to repair, 'g' to turn on or off the Gate keeper mode" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		target.takeDamage(player.getAttackDamage());
	}
	else if (input == "r")
		player.beRepaired(player.getRepairPoints());
	else if (input == "g")
	{
		if (player.getGuardGateMode() == false)
		{
			std::cout << BOLD << BLU << "ScavTrap is now in Gate keeper mode" << RESET << std::endl;
			player.setGuardGateMode(true);
		}
		else
		{
			std::cout << BLU << "ScavTrap is no longer in Gate keeper mode" << RESET << std::endl;
			player.setGuardGateMode(false);
		}
	}
	else
		std::cout << RED <<"Invalid input, please try again." << RESET << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::string	input;

	std::cout << BOLD << "Welcome to the ClapTrap vs ScavTrap game!" << RESET << std::endl;
	std::cout << "ClapTrap and ScavTrap will fight until one of them dies." << std::endl;
	std::cout << "ClapTrap has 10 " << GRN << "hit points" << RESET << " and 10 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "ScavTrap has 100 " << GRN << "hit points" << RESET << " and 50 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "Attacking and repairing cost 1 " << RED << "energy point" << RESET << " each." << std::endl;
	std::cout << std::endl;

	std::cout << "Please type the name of the ClapTrap: ";
	std::string clapTrapName;
	std::getline(std::cin, clapTrapName);
	ClapTrap	clapTrap(clapTrapName);
	std::cout << std::endl;
	
	std::cout << "Please type the names of the ScavTrap: ";
	std::string scavTrapName;
	std::getline(std::cin, scavTrapName);
	ScavTrap	scavTrap(scavTrapName);
	std::cout << std::endl;

	std::cout << "Please type how many " << GRN << "hit points" << RESET << " of damage each attack will cause." << std::endl;
	int clapTrapAttackDamage = getValidIntegerInput("ClapTraps's attack damage: \033[32mhit points\033[0m ScavTrap will lose when attacked: ");
	std::cout << BOLD << "ScavTrap's attack damage is fixed: " << RESET << GRN << "hit points"<< RESET <<" ClapTrap will lose when attacked is 20" << std::endl;
	clapTrap.setAttackDamage(clapTrapAttackDamage);
	std::cout << std::endl;

	std::cout << "Please type how many " << GRN << "hit points" << RESET << " each repair will give back." << std::endl;
	int clapTrapRepairPoints = getValidIntegerInput("ClapTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	int scavTrapRepairPoints = getValidIntegerInput("ScavTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	clapTrap.setRepairPoints(clapTrapRepairPoints);
	scavTrap.setRepairPoints(scavTrapRepairPoints);
	std::cout << std::endl;

	while (clapTrap.getHitPoints() > 0 && scavTrap.getHitPoints() > 0)
	{
		std::cout << "Choose player:" << std::endl;
		std::cout << "type 'c' for ClapTrap and 's' for ScavTrap" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			std::exit(0);
		}
		else if (input == "c")
			actionsClapTrap(clapTrap, scavTrap);
		else if (input == "s")
			actionsScavTrap(scavTrap, clapTrap);
		else
		{
			std::cout << RED << "Invalid input, please try again." << RESET << std::endl;
			continue;
		}
		clapTrap.printStatus();
		scavTrap.printStatus();
		scavTrap.guardGate();
		std::cout << std::endl;
		if (clapTrap.getHitPoints() <=0)
			std::cout << BOLD_YLW << "ScavTrap wins!" << RESET << std::endl;
		if (scavTrap.getHitPoints() <=0)
			std::cout << BOLD_YLW << "ClapTrap wins!" << RESET << std::endl;
		
	}
	return (0);
}
