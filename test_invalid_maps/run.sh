#!/bin/bash
EXECUTABLE=../cub3DS
ANSI_F_CYAN=$'\033[46m'
ANSI_RESET=$'\033[0m'

echo "test.cub"
./$EXECUTABLE test.cub
echo "test.cub2"
./$EXECUTABLE test.cub2
echo "<empty>"
./$EXECUTABLE
echo "test.cub as"
./$EXECUTABLE test.cub as

for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_res_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_res_00$i.cub
done
for (( i=10; i<=29; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_res_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_res_0$i.cub
done


for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_EA_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_EA_00$i.cub
done
for (( i=10; i<=22; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_EA_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_EA_0$i.cub
done

for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_NO_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_NO_00$i.cub
done
for (( i=10; i<=22; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_NO_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_NO_0$i.cub
done

for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_SO_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_SO_00$i.cub
done
for (( i=10; i<=22; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_SO_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_SO_0$i.cub
done

for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_WE_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_WE_00$i.cub
done
for (( i=10; i<=22; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_tex_WE_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_tex_WE_0$i.cub
done


for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_RGB_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_RGB_00$i.cub
done
for (( i=10; i<=42; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_RGB_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_RGB_0$i.cub
done


for (( i=1; i<=9; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_map_area_00$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_map_area_00$i.cub
done
for (( i=10; i<=27; i++ ))
do
	echo
   	echo $ANSI_F_CYAN "invalid_maps/invalid_map_area_0$i.cub" $ANSI_RESET
	./$EXECUTABLE invalid_maps/invalid_map_area_0$i.cub
done
