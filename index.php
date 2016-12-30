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

<?php include 'includes/header.inc'; //Encabezado de la página ?>
    
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