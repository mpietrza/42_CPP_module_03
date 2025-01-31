/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:55:28 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/31 17:47:29 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
		player.beRepaired(1);
	else
		std::cout << "Invalid input, please try again." << std::endl;
}

int main(void)
{
	ClapTrap	clap("Clap");
	ClapTrap	trap("Trap");
	std::string	input;

	while (clap.getHitPoints() > 0 && trap.getHitPoints() > 0)
	{
		std::cout << "Choose player:" << std::endl;
		std::cout << "type 'c' for Clap and 't' for Trap" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl - D pressed - exiting the game" << std::endl;
			std::exit(0);
		}
		else if (input == "c")
			actions(clap, trap);
		else if (input == "t")
			actions(trap, clap);
		else
			std::cout << "Invalid input, please try again." << std::endl;
		if (clap.getHitPoints() <=0)
			std::cout << "Trap wins!" << std::endl;
		if (trap.getHitPoints() <=0)
			std::cout << "Clap wins!" << std::endl;
		return (0);
	}
}
