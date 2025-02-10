/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:05:27 by mpietrza          #+#    #+#             */
/*   Updated: 2025/02/10 17:06:15 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <unistd.h>

//default constructor
FragTrap::FragTrap() : ClapTrap()
{
	_typeName = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "FragTrap created by the default constructor" << std::endl;
}

//parametrized constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_typeName = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;	
	std::cout << "FragTrap " << name << " created by the parametrized constructor" << std::endl;
}

//default copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << _name << " copied by the copy constructor" << std::endl;
}

//copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assignment operator called for FragTrap: " << this->_name << std::endl;
	return *this;
}

//destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Default destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << BOLD << MGT << "Hi fives Guys!!!" << std::endl;
	usleep(500000);
	std::cout << YLW << "Hi five!!!" << std::endl;
	usleep(500000);
	std::cout << CYN << "Hi five!!!" << std::endl;
	usleep(500000);
	std::cout << GRN << "Hi five!!!" << RESET << std::endl;
	usleep(500000);
}

