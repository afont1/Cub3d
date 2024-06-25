/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:31:29 by afont             #+#    #+#             */
/*   Updated: 2024/06/25 15:57:32 by afont            ###   ########.fr       */
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
# define ANGLE_STEP			1
# define FOV_BASE			100
# define FOV				60
# define SPEED				1000
# define FPS				60
# define MAP_RANGE			16
# define BORDER_WIDTH		5
# define MAP_SQUARE_SIZE	20
# define MAP_SIZE			((MAP_RANGE + 1) * MAP_SQUARE_SIZE)
# define CEN_MAP			(MAP_RANGE / 2) * MAP_SQUARE_SIZE + MAP_SQUARE_SIZE / 2
# define JSP				64

/* ************************************************************************** */
/*	-colors                                                                   */
/* ************************************************************************** */
# define CUBE_COLOR			0x006400
# define MAP_WALL_COLOR		0x2e2e2e
# define MAP_WALL_COLOR2	0x212121	
# define MAP_FLOOR_COLOR	0x474747
# define MAP_SKY_COLOR		0x100000

/* ************************************************************************** */
/*	-math                                                                     */
/* ************************************************************************** */
# define M_PI				3.14159265358979323846
# define M_PI2				M_PI / 2
# define M_PI3				3 * M_PI / 2
# define ONE_DR				0.01745329252

#endif