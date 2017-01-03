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
        <?php msgUsuario(); ?>   
    </div>
    
<?php include 'includes/footer.inc'; //Pie de la página ?>
