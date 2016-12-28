<!DOCTYPE html>
<!-- Desarrollo Web en Entorno Servidor -->
<!-- Tema 4: Desarrollo de aplicaciones web en PHP -->
<!-- Felipe Rodríguez Gutiérrez -->
<!-- Tarea: 04 Foro DWES -->
<html>
    
<head>
    <meta charset="UTF-8">
    <title>DWES - Tarea 3 - Felipe Rodríguez Gutiérrez</title>
    <link type="text/css" href="css/estilos.css" rel="stylesheet" />
    <?php include 'includes/funciones.inc'; ?>
    <?php conectar(); ?>
</head>

<body>
    
    <h1 class="centrado">TAREA 4: FORO DWES</h1>
    <h2 class="centrado">Felipe Rodríguez Gutiérrez</h2>
    
    <div class="login">
        <div class="login-head">REGISTRO DE USUARIO</div>
        <div id='login-body'>
            <div class="login-cuerpo-acceso">
                <?php 
                    registroUsuario(); 
                    formularioRegreso();
                ?>
            </div>
        </div>    
    </div>
    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</html>
