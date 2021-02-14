#!/bin/sh

gcc -L/home/wrac/discordRichpresence/source/lib/x86_64/ -Wall -Wpedantic -Wextra discordRichpresence.c richPresenceFunctions.c -o discordRichpresence -ldiscord_game_sdk


