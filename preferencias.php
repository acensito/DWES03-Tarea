<?php
    include 'includes/funciones.inc';
    session_start();
    if (!isset($_SESSION['usuario']) OR ($_SESSION['usuario'] == "Invitado")) {
        header("Location: index.php");
    }  
?>

<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<head>
    <meta charset="UTF-8">
    <title>DWES - Tarea 4 - Felipe Rodríguez Gutiérrez</title>
    <link type="text/css" href="css/<?php echo theme();?>.css" rel="stylesheet" />
</head>

<body>
    
    <h1 class="centrado">TAREA 4: FORO DWES</h1>
    <h2 class="centrado">Felipe Rodríguez Gutiérrez</h2>
        <div class="control">
            <div class="control-head">PANEL DE CONTROL</div>
            <div class='control-body'>
                <?php panelControl(); ?>
            </div>
        </div>

        <div class="control">
            <div class="control-head">MENSAJES</div>
            <div class='control-body'>
                <div class="centrado"><?php seleccionPreferencias(); ?></div>
            </div> 
            <?php msgUsuario(); ?> 
        </div>    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</html>