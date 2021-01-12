################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/articulo.c \
../src/cliente.c \
../src/fechas.c \
../src/informes.c \
../src/main.c \
../src/rubro.c \
../src/utn.c \
../src/venta.c 

OBJS += \
./src/articulo.o \
./src/cliente.o \
./src/fechas.o \
./src/informes.o \
./src/main.o \
./src/rubro.o \
./src/utn.o \
./src/venta.o 

C_DEPS += \
./src/articulo.d \
./src/cliente.d \
./src/fechas.d \
./src/informes.d \
./src/main.d \
./src/rubro.d \
./src/utn.d \
./src/venta.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


