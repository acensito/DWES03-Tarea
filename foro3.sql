-- phpMyAdmin SQL Dump
-- version 4.2.7.1
-- http://www.phpmyadmin.net
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 16-12-2015 a las 13:58:02
-- Versión del servidor: 5.6.20
-- Versión de PHP: 5.5.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `foro3`
--
CREATE DATABASE IF NOT EXISTS `foro3` DEFAULT CHARACTER SET utf8 COLLATE utf8_spanish_ci;
USE `foro3`;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `foreros`
--

DROP TABLE IF EXISTS `foreros`;
CREATE TABLE IF NOT EXISTS `foreros` (
  `login` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `password` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `email` varchar(50) COLLATE utf8_spanish_ci NOT NULL,
  `bloqueado` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

--
-- Volcado de datos para la tabla `foreros`
--

INSERT INTO `foreros` (`login`, `password`, `email`, `bloqueado`) VALUES
('usu1', '$1$Dg5.QS0.$jn69c/DGOL4.I7wNr1QqI0', 'usuario1@gmail.com', 0),
('usu2', '$1$1.2..i3.$t88.rn7imzbSr/3sQ8e.x/', 'usuario2@gmail.com', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `mensajes`
--

DROP TABLE IF EXISTS `mensajes`;
CREATE TABLE IF NOT EXISTS `mensajes` (
`id_mensaje` int(11) NOT NULL,
  `autor` varchar(20) COLLATE utf8_spanish_ci NOT NULL,
  `contenido` varchar(500) COLLATE utf8_spanish_ci NOT NULL,
  `fecha` date NOT NULL,
  `privado` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci AUTO_INCREMENT=1 ;

--
-- RELACIONES PARA LA TABLA `mensajes`:
--   `autor`
--       `foreros` -> `login`
--

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `foreros`
--
ALTER TABLE `foreros`
 ADD PRIMARY KEY (`login`);

--
-- Indices de la tabla `mensajes`
--
ALTER TABLE `mensajes`
 ADD PRIMARY KEY (`id_mensaje`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `mensajes`
--
ALTER TABLE `mensajes`
MODIFY `id_mensaje` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
