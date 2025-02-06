/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:19:46 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/06 17:39:34 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

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

class ClapTrap
{
	protected:
		std::string	_name;
		std::string _typeName;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		int			_repairPoints;
		
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void 		printStatus() const;

		int			getHitPoints() const;
		std::string	getName() const;
		int 		getAttackDamage() const;
		int			getEnergyPoints() const;
		int			getRepairPoints() const;

		void		setAttackDamage(int damage);
		void		setRepairPoints(int hitPoints);
};

#endif