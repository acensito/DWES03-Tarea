<?php
    include 'includes/funciones.inc';
    session_start();
    if (!isset($_SESSION['usuario']) OR ($_SESSION['usuario'] == "Invitado")) {
        header("Location: index.php");
    }  
?>

<?php include 'includes/header.inc'; //Encabezado de la página ?>
    
    <div class="control">
        <div class="control-head">PANEL DE CONTROL</div>
            <div class='control-body'>
                <?php panelControl(); ?>
            </div>
        </div>
    </div>
        
    <div class="control">
        <div class="control-head">PUBLICAR MENSAJE</div>
        <div class='control-body'>
            <?php envioMensaje(); ?>
        </div> 
        <?php msgUsuario(); ?> 
    </div>
    
    <div id="pie">Felipe Rodriguez Gutiérrez - DWES Tarea 4 - Curso 2015/2016</div>
</html>
