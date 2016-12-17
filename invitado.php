<?php
    include 'includes/funciones.inc';
    session_start();
    if (!isset($_SESSION['usuario']) OR ($_SESSION['usuario'] != "Invitado")) {
        header("Location: index.php");
    }  
?>

<!DOCTYPE html>
<!-- Desarrollo Web en Entorno Servidor -->
<!-- Tema 4: Desarrollo de aplicaciones web en PHP -->
<!-- Felipe Rodríguez Gutiérrez -->
<!-- Tarea: 04 Foro DWES -->
<html>
    
<head>
    <meta charset="UTF-8">
    <title>DWES - Tarea 4 - Felipe Rodríguez Gutiérrez</title>
    <link type="text/css" href="css/estilos.css" rel="stylesheet" />
</head>

<body>
    <h1 class="centrado">TAREA 4: FORO DWES</h1>
    <h2 class="centrado">Felipe Rodríguez Gutiérrez</h2>
    
    <div class="control">
        <div class="control-head">PANEL DE CONTROL INVITADOS</div>
        <div class='control-body'>
            <?php panelControlInvitado(); ?>
        </div>
        <?php msgUsuario(); ?>   
    </div>
    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</body>
</html>
