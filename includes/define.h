/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:31:29 by afont             #+#    #+#             */
/*   Updated: 2024/06/10 10:41:09 by afont            ###   ########.fr       */
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
# define WIN_WIDTH			1920
# define WIN_HEIGHT			1080
# define CIRCLE_RAD			5
# define MAP_SIZE			1024
# define ANGLE_STEP			0.03
# define PRECISION			(4.26666666666666666666666666667*3)
# define FOV				(60*PRECISION)
# define WW					(WIN_WIDTH/FOV)
# define SPEED				8
# define FPS				120
# define MAP_RANGE			16
# define BORDER_WIDTH		5

/* ************************************************************************** */
/*	-colors                                                                   */
/* ************************************************************************** */
# define CUBE_COLOR			0x006400
# define MAP_WALL_COLOR		0x2e2e2e
# define MAP_WALL_COLOR2	0x212121	
# define MAP_FLOOR_COLOR	0x474747

/* ************************************************************************** */
/*	-math                                                                     */
/* ************************************************************************** */
# define M_PI				3.14159265358979323846
# define M_PI2				M_PI / 2
# define M_PI3				3 * M_PI / 2
# define ONE_DR				(0.0174533/PRECISION)

#endif