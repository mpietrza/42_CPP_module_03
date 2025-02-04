/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:05:27 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/04 16:05:44 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
	std::cout << "ScavTrap created by the default constructor" << std::endl;
}

//parametrized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;	
	std::cout << "ScavTrap " << name << " created by the parametrized constructor" << std::endl;
}

//default copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << this->_name << " copied by the copy constructor" << std::endl;
}
//copy assigment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assigment operator called for ClapTrap :" << this->_name << std::endl;
	return *this;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Default destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

bool	ScavTrap::getGuardGateMode() const
{
	return this->_guardGateMode;
}

void	ScavTrap::setGuardGateMode(bool mode)
{
	this->_guardGateMode = mode;
}
