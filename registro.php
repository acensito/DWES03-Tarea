
<?php
    include 'includes/funciones.inc';
    conectar();
    include 'includes/header.inc'; 
?>
    
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
