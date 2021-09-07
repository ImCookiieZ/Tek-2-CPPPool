/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** mainWindow.hpp
*/

#ifndef RUSH3_MAINWINDOW_HPP
#define RUSH3_MAINWINDOW_HPP
#include <ncurses.h>

void printMainBorder(int y, int x);
void printTopLeft();
void printRam();
void printSwap(int x);
void printCPUPercentage(int index);
void printCPUMhz(int index);
int mainNcurses();
#endif //RUSH3_MAINWINDOW_HPP
