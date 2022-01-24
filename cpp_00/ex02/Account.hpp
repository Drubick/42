// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );//consigue el numero de cuentas
	static int	getTotalAmount( void );//consigue la cantidad total de dinero depositado
	static int	getNbDeposits( void );//consigue el numero de depositos creados
	static int	getNbWithdrawals( void );//consigue el numero de dinero retirado
	static void	displayAccountsInfos( void );//muestra la informacion de las cuentas

	Account( int initial_deposit );//cpnstructor con un deposito inicial al crear la clase cuenta
	~Account( void );

	void	makeDeposit( int deposit ); //genera un deposito
	bool	makeWithdrawal( int withdrawal );//retira dinero de la cuenta
	int		checkAmount( void ) const;//chekea la cantidad de dineros
	void	displayStatus( void ) const;// muestra el estado de la cuenta


private:

	static int	_nbAccounts; //numero de cuentas
	static int	_totalAmount; //total de dinero
	static int	_totalNbDeposits;// numero de depopsitos
	static int	_totalNbWithdrawals;// numero de retiradas

	static void	_displayTimestamp( void ); //entiendo que la hora a la que se retiro el dinero
//datos seguramente para displayear la info de las cuentas
	int				_accountIndex;//un index
	int				_amount;//dinero en la cuenta
	int				_nbDeposits;//numero de deppositos
	int				_nbWithdrawals;//numero de retiradas

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */