/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:31:29 by afont             #+#    #+#             */
/*   Updated: 2024/05/23 13:07:46 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* ************************************************************************** */
/*	-keycode                                                                  */
/* ************************************************************************** */
# define UP					119
# define DOWN				115
# define LEFT				97
# define RIGHT				100

/* ************************************************************************** */
/*	-game info                                                                */
/* ************************************************************************** */
# define WIN_WIDTH			1024
# define WIN_HEIGHT			512
# define CUBE_SIZE			10
# define MAP_SIZE			512
# define ANGLE_STEP			0.12

/* ************************************************************************** */
/*	-colors                                                                   */
/* ************************************************************************** */
# define CUBE_COLOR			0x006400
# define MAP_WALL_COLOR		0x808080
# define MAP_FLOOR_COLOR	0x000000

/* ************************************************************************** */
/*	-math                                                                     */
/* ************************************************************************** */
# define M_PI				3.14159265358979323846
# define M_PI2				M_PI / 2
# define M_PI3				3 * M_PI / 2
# define ONE_DR				0.0174533

#endif