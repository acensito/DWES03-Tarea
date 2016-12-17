<?php
    include 'includes/funciones.inc';
    session_start();
    if (isset($_SESSION['usuario'])) {
        if ($_SESSION['usuario'] === "Invitado") {
            header("Location: invitado.php");
        } else {
            header("Location: foro.php");
        }
    }    
    $error = acceso();
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
    
    <div class="login">
        <div class="login-head">LOGIN</div>
        <div id='login-body'>
            <div class="login-cuerpo-acceso">
            <form action='index.php' method='post'>
                <?php echo $error; ?>
                <div class="campo">
                    <label for='usuario' >Usuario:</label><br/>
                    <input type='text' name='usuario' id='usuario' maxlength="50" placeholder="usuario"/><br/>
                </div>

                <div class="campo">
                    <label for='password' >Contraseña:</label><br/>
                    <input type='password' name='password' id='password' maxlength="50" placeholder="contraseña"/><br/>
                </div>

                <div class='login-botones'>
                    <button class="btn" type="submit" name="enviar">Acceder</button><br />
                </div>
            </form>
                 
            <form action="registro.php" method="post">
                <div class='login-botones'>
                    <button class="btn" type="submit" name="registro">Registrar usuario</button><br />
                </div>
            </form>
                 
            <form action="index.php" method="post">
                <div class='login-botones'>
                    <button class="btn" type="submit" name="invitado">Modo invitado</button><br />
                </div>
            </form>
                 
            </div>
        </div>    
    </div>
    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</html>