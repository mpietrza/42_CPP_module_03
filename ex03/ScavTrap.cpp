/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:05:27 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/06 18:59:58 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	_typeName = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGateMode = false;
	std::cout << "ScavTrap created by the default constructor" << std::endl;
}

//parametrized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_typeName = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;	
	_guardGateMode = false;
	std::cout << "ScavTrap " << name << " created by the parametrized constructor" << std::endl;
}

//default copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_guardGateMode = other._guardGateMode;
	std::cout << "ScavTrap " << this->_name << " copied by the copy constructor" << std::endl;
}

//copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_guardGateMode = other._guardGateMode;
	}
	std::cout << "Copy assignment operator called for ScavTrap: " << this->_name << std::endl;
	return *this;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_guardGateMode == true)
	{
		std::cout << BOLD << BLU << _typeName << " is in Gate keeper mode" << RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << BLU << _typeName << " is not in Gate keeper mode" << RESET << std::endl;
		std::cout << std::endl;
	}
}

bool ScavTrap::getGuardGateMode() const
{
	return _guardGateMode;
}

void ScavTrap::setGuardGateMode(bool mode)
{
	_guardGateMode = mode;
}
