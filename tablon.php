<?php
    include 'includes/funciones.inc';
    session_start();
    if (!isset($_SESSION['usuario'])) {
        header("Location: index.php");
    }    
?>

<?php include 'includes/header.inc'; //Encabezado de la página ?>

    <?php 
    if ($_SESSION['usuario'] != "Invitado") {
    ?>
        <div class="control">
            <div class="control-head">PANEL DE CONTROL</div>
            <div class='control-body'>
                <?php panelControl(); ?>
            </div>
        </div>

        <div class="control">
            <div class="control-head">MENSAJES</div>
            <div class='control-body'>
                <div class="centrado"><?php mensajesPrivados(); ?></div>
            </div> 
            <?php msgUsuario(); ?> 
        </div>
    <?php
    } else {
        ?>
        <div class="control">
            <div class="control-head">MENSAJES</div>
            <div class='control-body'>
                <div class="centrado"><?php mensajesPublicos(); ?></div></br>
                <div class="centrado"><?php formularioRegreso(); ?></div>
                <?php msgUsuario(); ?>
            </div> 
        </div><?php 
    }?>

    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</html>
