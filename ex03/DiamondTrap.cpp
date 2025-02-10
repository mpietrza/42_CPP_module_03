/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:58 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/10 17:08:18 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <unistd.h>

//default constructor
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	_typeName = "DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap created by the default constructor" << std::endl;
}

//parametrized constructor
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_typeName = "DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_guardGateMode = ScavTrap::_guardGateMode;

	std::cout << "DiamondTrap created by the parametrized constructor" << std::endl;
}

//default copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	_guardGateMode = ScavTrap::_guardGateMode;
	std::cout << "DiamondTrap " << this->_name << " copied by the copy constructor" << std::endl;
}

//copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		DiamondTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assignment operator calld for DiamondTrap" << this->_name << std::endl;
	return *this;
}

//destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Default destructor called"  << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
	usleep(5000000);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

