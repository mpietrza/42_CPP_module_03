/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:38:31 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/06 19:04:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//default constructor
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap created by the default constructor" << std::endl;
}

//parametrized constructor
ClapTrap::ClapTrap(const std::string &name) : _name(name), _typeName("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " created by the parametrized constructor" << std::endl;
}

//default copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << this->_name << " copied by the copy constructor" << std::endl;
}

//copy assigment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Default destructor called" << std::endl;
}

//public member function attack
void	ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << _typeName << " " << _name << " attacks " << target 
				  << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints == 0)
		std::cout << _typeName << " " << _name << " has no energy left to attack" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _typeName << " " << _name << " has no hit points left to attack" << std::endl;
}

//public member function takeDamage
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << _typeName << " " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << _typeName << " " << _name << " is already destroyed!" << std::endl;
}

//public member function beRepaired
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << _typeName << " " << _name << " has been repaired by " << amount << " points!" << std::endl;
	}
	else
		std::cout << _typeName << " " << _name << " lacks energy points to be repaired!" << std::endl;
}

void ClapTrap::printStatus() const
{
	std::cout << BOLD << _typeName << " " << _name << RESET << std::endl;
	std::cout << GRN << "Hit points" << RESET << ": " << _hitPoints << std::endl;
	std::cout << RED << "Energy points" << RESET << ": " << _energyPoints << std::endl;
	std::cout << "Attack damage: "<< GRN << "hit points" << RESET << " the enemy will lose: " << _attackDamage << std::endl;
	std::cout << "Repair points: " << GRN << "hit points " << RESET << _name << " gets back each repair: " << this->_repairPoints << std::endl;
	std::cout << std::endl;
}

//getter for the points
int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

//getter for the name
std::string ClapTrap::getName() const
{
	return _name;
}

//getter for the attackDamage
int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

//getter for the energy points
int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

//getter for the repair points
int ClapTrap::getRepairPoints() const
{
	return _repairPoints;
}

//setter for the attackDamage
void ClapTrap::setAttackDamage(int damage)
{
	_attackDamage = damage;
}

//setter for the repair points
void ClapTrap::setRepairPoints(int hitPoints)
{
	_repairPoints = hitPoints;
}

