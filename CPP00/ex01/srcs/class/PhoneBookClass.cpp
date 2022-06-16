/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:17:36 by aguay             #+#    #+#             */
/*   Updated: 2022/06/16 18:14:53 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookClass.hpp"

PhoneBookClass::PhoneBookClass(void)
{
	return ;
}

PhoneBookClass::~PhoneBookClass(void)
{
	for (int i = 0; i < PhoneBookClass::getNbInst(); i++)
	{
		delete _repertoire[i];
	}
	return ;
}

int	PhoneBookClass::getNbInst(void)
{
	return ((int)PhoneBookClass::_nbInst);
}

int	PhoneBookClass::getIndex(void)
{
	return (PhoneBookClass::_index);
}

void	PhoneBookClass::setRepertoire(Contact *cont, int index)
{
	if (index < 8 && index >= 0)
		this->_repertoire[index] = cont;
	return;
}

void	PhoneBookClass::addContact(Contact *cont)
{
	if (PhoneBookClass::getIndex() == 8)
	{
		PhoneBookClass::_index = 0;
		PhoneBookClass::setRepertoire(cont, PhoneBookClass::getIndex());
	}
	else
		PhoneBookClass::setRepertoire(cont, PhoneBookClass::getIndex());
	PhoneBookClass::_index++;
	if (PhoneBookClass::getNbInst() < 8)
		PhoneBookClass::_nbInst++;
}

void	PhoneBookClass::showRepertoire(void)
{
	for (int i = 0; i <= 9; i++)
	{
		if (i == 0 || i == 9)
			std::cout << "*---------------------------------*\n";
		else if (i - 1 < PhoneBookClass::getNbInst())
		{
			std::cout << "| " << i - 1 << " | ";
			std::cout << _repertoire[i - 1]->getFirstName().substr(0, 6);
			if ( _repertoire[i - 1]->getFirstName().size() >= 7)
				std::cout << ". | ";
			else
			{
				for (int x =  _repertoire[i - 1]->getFirstName().size(); x <= 7; x++)
					std::cout << ' ';
				std::cout << "| ";
			}
			std::cout << _repertoire[i - 1]->getLastName().substr(0, 6);
			if ( _repertoire[i - 1]->getLastName().size() >= 7)
				std::cout << ". | ";
			else
			{
				for (int x =  _repertoire[i - 1]->getLastName().size(); x <= 7; x++)
					std::cout << ' ';
				std::cout << "| ";
			}
			std::cout << _repertoire[i - 1]->getNickName().substr(0, 6);
			if ( _repertoire[i - 1]->getNickName().size() >= 7)
				std::cout << ". ";
			else
			{
				for (int x =  _repertoire[i - 1]->getNickName().size(); x <= 7; x++)
					std::cout << ' ';
				std::cout << "|";
			}
			std::cout << std::endl;
		}
		else
			std::cout << "|                                 |\n";
	}
}

size_t	PhoneBookClass::_nbInst = 0;
int		PhoneBookClass::_index = 0;
