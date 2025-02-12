/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:55:28 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/10 17:20:15 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <climits>
#include <cstdlib>

int getValidIntegerInput(const std::string& prompt) 
{
	std::string input;
	int value;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof() == true) 
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			exit(0);
		}
		try 
		{
			value = std::atoi(input.c_str());
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

/*Yes, you can use templates in your files because templates are a core 
feature of C++ and not part of the STL. The restriction applies specifically 
to STL containers (like std::vector, std::map, etc.) and algorithms (like those
 in <algorithm>). You can still use templates for generic programming as long
 as you implement your own data structures instead of relying on STL containers.
 */
template <typename T>
void actionsClapTrap(ClapTrap &player, T &target)
{
	std::string	input;
	std::cout << "Choose action for ClapTrap: 'a' to attack, 'r' to repair" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		if (player.getEnergyPoints() > 0 && player.getHitPoints() > 0)
			target.takeDamage(player.getAttackDamage());
	}
	else if (input == "r")
		player.beRepaired(player.getRepairPoints());
	else
		std::cout << RED <<"Invalid input, please try again." << RESET << std::endl;
	std::cout << std::endl;
}

template <typename T>
void actionsScavTrap(ScavTrap &player, T &target)
{
	std::string	input;
	std::cout << "Choose action for ScavTrap: 'a' to attack, 'r' to repair, 'g' to turn on or off the Gate keeper mode" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		if (player.getEnergyPoints() > 0 && player.getHitPoints() > 0)
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

template <typename T>
void actionsFragTrap(FragTrap &player, T &target)
{
	std::string	input;
	std::cout << "Choose action for FragTrap: 'a' to attack, 'r' to repair, 'h' to request high five to the other players" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		if (player.getEnergyPoints() > 0 && player.getHitPoints() > 0)
			target.takeDamage(player.getAttackDamage());
	}
	else if (input == "r")
		player.beRepaired(player.getRepairPoints());
	else if (input == "h")
		player.highFivesGuys();
	else
		std::cout << RED <<"Invalid input, please try again." << RESET << std::endl;
	std::cout << std::endl;
}

template <typename T>
void actionsDiamondTrap(DiamondTrap &player, T &target)
{
	std::string	input;
	std::cout << "Choose action for ScavTrap: 'a' to attack, 'r' to repair, 'g' to turn on or off the Gate keeper mode, 'h' to request high five to the other players, 'w' to tell who is he" << std::endl;
	std::getline(std::cin, input);
	if (input == "a")
	{
		player.attack(target.getName());
		if (player.getEnergyPoints() > 0 && player.getHitPoints() > 0)
			target.takeDamage(player.getAttackDamage());
	}
	else if (input == "r")
		player.beRepaired(player.getRepairPoints());
	else if (input == "g")
	{
		if (player.getGuardGateMode() == false)
		{
			std::cout << BOLD << BLU << "DiamondTrap is now in Gate keeper mode" << RESET << std::endl;
			player.setGuardGateMode(true);
		}
		else
		{
			std::cout << BLU << "DiamondTrap is no longer in Gate keeper mode" << RESET << std::endl;
			player.setGuardGateMode(false);
		}
	}
	else if (input == "h")
		player.highFivesGuys();
	else if (input == "w")
		player.whoAmI();
	else
		std::cout << RED <<"Invalid input, please try again." << RESET << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::string	input;

	std::cout << BOLD << "Welcome to the ClapTrap vs ScavTrap vs FragTrap vs DiamondTrap game!" << RESET << std::endl;
	std::cout << "ClapTrap, ScavTrap, FragTrap and DiamondTrap will fight until one of them dies." << std::endl;
	std::cout << "ClapTrap has 10 " << GRN << "hit points" << RESET << " and 10 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "ScavTrap has 100 " << GRN << "hit points" << RESET << " and 50 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "FragTrap has 100 " << GRN << "hit points" << RESET << " and 100 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "DiamondTrap has 100 " << GRN << "hit points" << RESET << " and 50 " << RED << "energy points" << RESET << "." << std::endl;
	std::cout << "Attacking and repairing cost 1 " << RED << "energy point" << RESET << " each." << std::endl;
	std::cout << std::endl;

	std::cout << "Please type the name of the ClapTrap: ";
	std::string clapTrapName;
	std::getline(std::cin, clapTrapName);
	ClapTrap	clapTrap(clapTrapName);
	std::cout << std::endl;
	
	std::cout << "Please type the name of the ScavTrap: ";
	std::string scavTrapName;
	std::getline(std::cin, scavTrapName);
	ScavTrap	scavTrap(scavTrapName);
	std::cout << std::endl;

	std::cout << "Please type the name of the FragTrap: ";
	std::string fragTrapName;
	std::getline(std::cin, fragTrapName);
	FragTrap	fragTrap(fragTrapName);
	std::cout << std::endl;
	
	std::cout << "Please type the name of the DiamondTrap: ";
	std::string diamondTrapName;
	std::getline(std::cin, diamondTrapName);
	DiamondTrap	diamondTrap(diamondTrapName);
	std::cout << std::endl;

	std::cout << "Please type how many " << GRN << "hit points" << RESET << " of damage each attack will cause." << std::endl;
	signed int clapTrapAttackDamage = getValidIntegerInput("ClapTraps's attack damage: \033[32mhit points\033[0m the enemy will lose when attacked: ");
	std::cout << BOLD << "ScavTrap's attack damage is fixed: " << RESET << GRN << "hit points"<< RESET <<" the enemy will lose when attacked is 20" << std::endl;
	std::cout << BOLD << "FragTrap's attack damage is fixed: " << RESET << GRN << "hit points"<< RESET <<" the enemy will lose when attacked is 30" << std::endl;
	std::cout << BOLD << "DiamondTrap's attack damage is the same as FragTraps: " << RESET << GRN << "hit points"<< RESET <<" the enemy will lose when attacked is 30" << std::endl;
	clapTrap.setAttackDamage(clapTrapAttackDamage);
	std::cout << std::endl;

	std::cout << "Please type how many " << GRN << "hit points" << RESET << " each repair will give back." << std::endl;
	signed int clapTrapRepairPoints = getValidIntegerInput("ClapTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	signed int scavTrapRepairPoints = getValidIntegerInput("ScavTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	signed int fragTrapRepairPoints = getValidIntegerInput("FragTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	signed int diamondTrapRepairPoints = getValidIntegerInput("DiamondTrap's amount of \033[32mhit points\033[0m each time it repairs: ");
	clapTrap.setRepairPoints(clapTrapRepairPoints);
	scavTrap.setRepairPoints(scavTrapRepairPoints);
	fragTrap.setRepairPoints(fragTrapRepairPoints);
	diamondTrap.setRepairPoints(diamondTrapRepairPoints);
	std::cout << std::endl;

	while (1)
	{
		std::cout << "Choose player:" << std::endl;
		std::cout << "type 'cs' for ClapTrap vs ScavTrap,    'cf' for ClapTrap vs FragTrap,     'cd' for ClapTrap vs DiamondTrap" << std::endl
				  << "     'sc' for ScavTrap vs ClapTrap,    'sf' for ScavTrap vs FragTrap,     'sd' for ScavTrap vs DiamondTrap" << std::endl
				  << "     'fc' for FragTrap vs ClapTrap,    'fs' for FragTrap vs ScavTrap,     'fd' for FragTrap vs DiamondTrap" << std::endl
				  << "     'dc' for DiamondTrap vs ClapTrap, 'ds' for DiamondTrap vs ScavTrap,  'df' for DiamondTrap vs FragTrap." << std::endl;

		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			exit(0);
		}
		else if (input == "cs")
			actionsClapTrap(clapTrap, scavTrap);
		else if (input == "cf")
			actionsClapTrap(clapTrap, fragTrap);
		else if (input == "cd")
			actionsClapTrap(clapTrap, diamondTrap);
		else if (input == "sc")
			actionsScavTrap(scavTrap, clapTrap);
		else if (input == "sf")
			actionsScavTrap(scavTrap, fragTrap);
		else if (input == "sd")
			actionsScavTrap(scavTrap, diamondTrap);
		else if (input == "fc")
			actionsFragTrap(fragTrap, clapTrap);
		else if (input == "fs")
			actionsFragTrap(fragTrap, scavTrap);
		else if (input == "fd")
			actionsFragTrap(fragTrap, diamondTrap);
		else if (input == "dc")
			actionsDiamondTrap(diamondTrap, clapTrap);
		else if (input == "ds")
			actionsDiamondTrap(diamondTrap, scavTrap);
		else if (input == "df")
			actionsDiamondTrap(diamondTrap, fragTrap);
		else
		{
			std::cout << RED << "Invalid input, please try again." << RESET << std::endl;
			continue;
		}
		clapTrap.printStatus();
		scavTrap.printStatus();
		scavTrap.guardGate();
		fragTrap.printStatus();
		diamondTrap.printStatus();
		diamondTrap.guardGate();
		if (clapTrap.getHitPoints() <=0 && fragTrap.getHitPoints() <=0 && diamondTrap.getHitPoints() <=0)
		{
			std::cout << BOLD_YLW << "ScavTrap wins!" << RESET << std::endl;
			break;
		}
		if (scavTrap.getHitPoints() <=0 && fragTrap.getHitPoints() <=0 && diamondTrap.getHitPoints() <=0)
		{
			std::cout << BOLD_YLW << "ClapTrap wins!" << RESET << std::endl;
			break;
		}
		if (clapTrap.getHitPoints() <=0 && scavTrap.getHitPoints() <=0 && diamondTrap.getHitPoints() <=0)
		{
			std::cout << BOLD_YLW << "FragTrap wins!" << RESET << std::endl;
			break;
		}
		if (clapTrap.getHitPoints() <=0 && scavTrap.getHitPoints() <=0 && fragTrap.getHitPoints() <=0)
		{
			std::cout << BOLD_YLW << "DiamondTrap wins!" << RESET << std::endl;
			break;
		}		
	}
	return (0);
}
