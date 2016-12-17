<?php

/* FUNCIONES BASES DE DATOS */
/****************************/

/**
 * Función que conectará con la base de datos. A modificar la IP por localhost 
 * dado que las pruebas se han realizado con un servidor remoto.
 * 
 * @global PDO $con conexión a la base de datos.
 */
function conectar(){
    $db_host = 'localhost';  //  hostname Por defecto: localhost 192.168.0.250 en red
    $db_name = 'foro4';  //  databasename
    $db_user = 'dwes';  //  username
    $user_pw = 'dwes';  //  password

    try {
        global $con; //Se realiza como variable global para tener la misma disponible en cualquier página
        $con = new PDO('mysql:host='.$db_host.'; dbname='.$db_name, $db_user, $user_pw);
        $con->exec("set names utf8");
    } catch (PDOException $e) { //Se capturan los mensajes de error
        $err = $e->getCode();
        $msj = $e->getMessage(); 
        echo "<div class='errcon'><p>" . $err . " " . $msj . "</p></div>"; //Se devuelven los mismos si existieran
    }
}

/**
 * Funcion destinada a desconectar con la BD;
 */
function desconectar() {
    unset($GLOBALS['con']);
}

/**
 * Funcion que inicia sesión
 */
function inicioSesion() {
    session_start(); //Inicia la sesion
    if (isset($_SESSION)) {
        $usuario = $_SESSION['usuario']; //Establece el usuario en la sesion
        $hora = $_SESSION['hora']; //Establece la hora de la sesion
    }
}

/* FUNCIONES FORMULARIOS */
/*************************/

/**
 * Formulario con un voton de regreso al index.php que puede ser utilizado como volver
 */
function formularioRegreso() {
    ?>
    <form action="index.php" method="post">
        <div class='login-botones'>
            <button class="btn" type="submit" name="volver">Volver</button><br />
        </div>
    </form>
    <?php
}

/**
 * Formulario de registro. Los parametros son para devolver el mail o el usuario en el caso de fallar en el registro
 * 
 * @param type $usuario Usuario si ha sido introducido previamente por el usuario como valor por defecto
 * @param type $email   Email si ha sido introducido previamente por el usuario como valor por defecto
 */
function formularioRegistro($usuario = "", $email = "") {
    ?>
    <form action='registro.php' method='post'>
        <div class="campo">
            <label for='usuario' >Usuario</label><br/>
            <input type='text' name='usuario' id='usuario' maxlength="50" placeholder="usuario" value="<?php echo $usuario ?>"/><br/>
        </div>

        <div class="campo">
            <label for='usuario' >E-Mail</label><br/>
            <input type='email' name='email' id='email' maxlength="50" placeholder="e-mail" value="<?php echo $email?>"/><br/>
        </div>

        <div class="campo">
            <label for='password' >Contraseña</label><br/>
            <input type='password' name='password' id='password' maxlength="50" placeholder="contraseña"/><br/>
        </div>

        <div class="campo">
            <label for='password2' >Repite Contraseña</label><br/>
            <input type='password' name='password2' id='password2' maxlength="50" placeholder="repite contraseña"/><br/>
        </div>

        <div class='login-botones'>
            <button class="btn" type="submit" name="registrarUsu">Guardar</button><br />
        </div>
    </form>
    <?php
}

/**
 * Formulario con los botones del panel de control para usuarios registrados
 */
function panelControl() {
    ?>
    <div class="control-pane-menu">
        <form action='mensaje.php' method='post'>
            <button class="control-pane-btn" type="submit" name="mensaje">Mensaje</button>
        </form>
        <form action='tablon.php' method='post'>
            <button class="control-pane-btn" type="submit" name="tablon">Tablón</button>
        </form>
        <form action='preferencias.php' method='post'>
            <button class="control-pane-btn" type="submit" name="preferencias">Preferencias</button>
        </form>
        <?php salir(); ?>
    </div>
    <?php
}

/**
 * Funcion de panel de control para invitados, con menos funciones que el principal
 */
function panelControlInvitado() {
    ?>
    <div class="control-pane-menu">
        <form action='tablon.php' method='post'>
            <button class="control-pane-btn" type="submit" name="tablon">Tablón</button>
        </form>
        <?php salir(); ?>
    </div>
    <?php
}

/**
 * Formulario con el boton salir para usuarios registrados e invitados
 */
function salir() {
    ?>
    <form action='logout.php' method='post'>
        <button class="control-pane-btn" type="submit" name="salir">Salir</button>
    </form>
    <?php
}

/**
 * Formulario de campo de texto para enviar un mensaje. Con casilla checkbox para definir si es privado o no
 */
function formularioMensaje() {
    ?>
    <div class="msg-pane">
        <form name="frm" action='mensaje.php' method='post'>
            <label>Texto del mensaje</label></br>
            <textarea id="frmtxt" class="txt-pane" rows="4" cols="50" maxlength="500" name="comment" placeholder="Introduzca aqui su texto"></textarea></br>
            <input name="checkbox" type="checkbox" ><label>Privado</label></br>
            <button class='control-pane-btn' type="submit" name="postear">Enviar mensaje</button>
        </form>
    </div>
    <?php
}

/**
 * Formulario para establecer las preferencias de cada usuario sobre el theme. Se controla con un combobox.
 * Se añade un boton para eliminar las preferencias y otro para guardar los cambios
 */
function formularioPreferencias() {
    ?>
    <div>
        <form name="preferencias" action='preferencias.php' method='post'>
            <label>Elige un theme</label></br>
            <select class="pref-combo" name="combo">
                <option value="estilos">Theme por defecto</option>
                <option value="estilos1">Theme azul</option>
                <option value="estilos2">Theme marino</option>
            </select></br>
            <button class='control-pane-btn' type="submit" name="restablecer">Restablecer cambios</button>
            <button class='control-pane-btn' type="submit" name="guardar">Guardar cambios</button>
        </form>
    </div>
    <?php
}

/**
 * Formulario que muestra un mensaje con el login del usuario y su fecha de login
 */
function msgUsuario() {
    if ($_SESSION) { //Si existe sesion alguna... muestra un mensaje recuperando el usuario de la sesion y hora establecidos
        echo "<div class='control-foot'>Bienvenido " . $_SESSION['usuario'] . ", ultima sesión a las " . date("H:i", $_SESSION['hora']) . "</div>";
    }
}

/* FUNCIONES DE CONTROL */
/************************/

/**
 * Funcion para el registro de usuario nuevo
 */
function registroUsuario(){
    if (isset($_POST['registrarUsu'])) { //Si se ha pulsado el boton de registrar...
        
        /* Recabamos los datos obtenidos por formulario */
        $usuario = $_POST['usuario'];
        $email = $_POST['email'];
        $password = $_POST['password'];
        $password2 = $_POST['password2'];
        
        /* Valida los datos recibidos, volcandolos en un flag de control*/
        $flag = validar_usuario($usuario, $password, $password2, $email);
        
        if ($flag) { //Si el flag de control es negativo...
            echo $flag; //Mostrará los errores obtenidos....
            formularioRegistro($usuario, $email); //Muestra de nuevo el formulario con los datos introducidos para corregir
        } else { //caso de que todo este correcto... 
            
            /* Insertamos el usuario.
             * Previamente encriptamos la clave facilitada por el usuario y asignamos el bloqueo a 1 (true, bloqueado) */
            $password = crypt($password);
            $bloqueado = true;
            
            try { //Preparamos la consulta
           
                $consulta = "INSERT INTO foreros (login, password, email, bloqueado) VALUES (:login, :pass, :email, :bloqueado)";

                $resultado = $GLOBALS['con']->prepare($consulta);
                $resultado->bindParam(":login", $usuario);
                $resultado->bindParam(":pass", $password);
                $resultado->bindParam(":email", $email);
                $resultado->bindParam(":bloqueado", $bloqueado);
                
                $resultado->execute(); //Ejecutamos la consulta, añadimos el usuario

                echo "<p class='perfect'>Se ha creado el usuario " . $usuario . " correctamente</p>"; //Mensaje de feedback a mostrar...
            } catch (PDOException $e) { //En caso de errores
                echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>"; //Se captura el error y se muestra
            }
        }
        
    } else { //En cualquier otro caso, no se ha pulsado el boton.
        formularioRegistro(); //Mostramos el formulario de registro, sin parametros.
    }
}

/**
 * Funcion que comprueba si se ha intentado hacer login en la web, ya sea como usuario o como invitado
 * 
 * @return type Devuelve diferentes mensajes de error posibles
 */
function acceso() {
        
    if (isset($_POST['enviar'])) { // Comprobamos si ya se ha enviado el formulario, si es asi
        /* Recabamos los datos del usuario de la sesion */
        $usuario = $_POST['usuario'];
        $password = $_POST['password'];
       
        if (empty($usuario)) { //Si el campo usuario esta vacio, se procede a devolver el correspondiente mensaje de error
            return $error = "<div class='errcon'><p>Debes introducir un nombre de usuario. Si no tienes usuario, puedes crearte uno registrandote o puedes acceder en modo invitado.</p></div>";
//        } else if (empty($password)) { //Este campo es optativo, yo he tomado como un intento de error malo el loguearse sin meter clave alguna.
//            return $error = "Debes de introducir una contraseña.";
        } else { //En el caso de que haya introducido un usuario...
            /*  Comprobamos las credenciales con la base de datos
             *  Conectamos a la base de datos */
            conectar();

            /* Ejecutamos la consulta para comprobar las credenciales */
            try {
                $consulta = "SELECT * FROM foreros WHERE login = :login";

                $resultado = $GLOBALS['con']->prepare($consulta);
                $resultado->bindParam(":login", $usuario);
                $resultado->execute();

                $registro = $resultado->fetch(); //Obtenemos el resultado
                
                if ($registro['bloqueado'] == true) { //Si esta bloqueado, no se prosigue y se manda mensaje de feedback
                    return $error = "<div class='errcon'><p>Usuario bloqueado. Contacte con el administrador</p></div>";
                } else { //En el caso de no estar bloqueado, y existe...
                    if ($resultado->rowCount() > 0) {
                        $hash = $registro['password']; //Obtenemos el password de la BD
                        $clave = password_verify($password, $hash); //Lo comparamos con el enviado por formulario
                        if ($clave) { //Si la clave es buena, iniciamos la sesion...
                            $_SESSION['usuario'] = $usuario; //Obtenemos el usuario
                            $_SESSION['hora'] = time();      //Obtenemos la hora
                            header("Location: foro.php");    //Redirijimos a la pagina de usuario registrado, foro.php
                        } else { //En el caso de existir el usuario y tener una clave incorrecta
                            if (!isset($_SESSION['usuarioIntento'])) { //Si no hay definido un usuario de intento...
                                $_SESSION['usuarioIntento'] = $usuario; //Definimos ese usario para almacenar sus intentos
                                $_SESSION['intentos'] = 1; //Le establecemos su primer intento
                            } else if ($_SESSION['usuarioIntento'] == $usuario && isset($_SESSION['usuarioIntento'])) { //Si ya hay usuario de intento definido y sigue siendo el mismo
                                $_SESSION['intentos']++; //Le sumamos al contador de intentos uno más
                                if ($_SESSION['intentos'] >= 3) { //Si es igual o mayor que 3 el numero de intentos (porsiacaso), bloqueamos dicho usuario
                                    /* Ctreamos la consulta y le actualizamos el campo bloqueado al valor true */
                                    try {
                                        $consulta = "UPDATE foreros SET bloqueado = true WHERE login = :usuario";
                                        $resultado = $GLOBALS['con']->prepare($consulta);
                                        $resultado->bindParam(":usuario", $usuario);
                                        $resultado->execute();

                                        return $error = "<div class='errcon'><p>Usuario bloqueado. Contacte con el administrador</p></div>"; //Mandamos un mensaje de feedback 
                                    } catch (PDOException $e) { //En el caso de obtener un error, se captura el mensaje y se muestra
                                        echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>";
                                    }
                                }
                            } else { //En el caso de no ser el mismo usuario el que se ha introducido que el anterior intento, reseteamos el contador a 1 a ese usuario
                                $_SESSION['usuarioIntento'] = $_POST['usuario']; //Obtenemos la identidad de este nuevo usuario
                                $_SESSION['intentos'] = 1; //Le establecemos el contador a 1 de nuevo
                            }   
                            return $error ="<div class='errcon'><p>Clave incorrecta. Lleva " . $_SESSION['intentos'] . " intento de 3.</p></div>"; //Mandamos un mensaje de feedback
                        }
                    } else { //No existe el usuario
                        return $error = "<div class='errcon'><p>No existe el usuario. Entre como invitado o registrese como usuario</p></div>";
                    } 
                }

            } catch (PDOException $e) { //En el caso de obtener un error, se captura el mensaje y se muestra
                echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>";
            }
        }
        
   } else if (isset($_POST['invitado'])) { //En el caso de pulsar el boton de invitado..
       $_SESSION['usuario'] = 'Invitado'; //Establecemos un usuario Invitado
       $_SESSION['hora'] = time(); //Establecemos su hora de conexion
       header("Location: invitado.php"); //Redirigimos a su web
   } else { //En cualquier otro tipo de error
       return $error = "Introduzca un nombre de usuario y una contraseña o acceda como invitado"; //Mensaje de feedback
   }

}

/**
 * Funcion para enviar un mensaje
 */
function envioMensaje() {
    if (isset($_POST['postear'])) { //Si se ha pulsado el boton de postear...
        $mensaje = nl2br(htmlspecialchars($_POST['comment'])); //Volcamos el mensaje en la variable. Mantenemos los saltos de linea y caracteres especiales
        $flag = validar_mensaje($mensaje); //Comprobamos que el mensaje no supera los 500 caracteres y que no esta vacio
        
        if ($flag) { //Si existen errores
            echo $flag; //Imprime los errores
            formularioMensaje(); //Muestra de nuevo ese formulario
        } else { //Si no existen errores, insertamos el mensaje
            //Obtenemos el resto de datos para insertar el post
            $usuario = $_SESSION['usuario']; //Obtenemos el usuario de la sesion
            if (isset($_POST['checkbox'])) { //Si esta definida la casilla de privado...
                $privado = true; //Su valor será true
            } else { //En otro caso... si no esta pulsado...
                $privado = false; //Su valor sera false
            }
            $fecha = date("Y-m-d"); //Obtenemos la fecha actual en formato AAAA-mm-dd
            
            conectar(); //Conectamos la base de datos
            
            /* Preparamos la consulta y ejecutamos la inserción del mensaje */
            try {
                $consulta = "INSERT INTO mensajes (autor, contenido, fecha, privado) VALUES (:usuario, :mensaje, :fecha, :privado)";

                $resultado = $GLOBALS['con']->prepare($consulta);
                $resultado->bindParam(":usuario", $usuario);
                $resultado->bindParam(":mensaje", $mensaje);
                $resultado->bindParam(":fecha", $fecha);
                $resultado->bindParam(":privado", $privado);
                $resultado->execute();

                echo "<p class='perfect'>Se ha enviado el mensaje correctamente</p>"; //Mandamos un mensaje de feedback
            } catch (PDOException $e) { //En el caso de obtener un error, se captura el mensaje y se muestra
                echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>";
            }
        }
    } else { //En caso de no haber mandado nada, establecemos el formulario sencillo por defecto
        formularioMensaje();
    }
}

/**
 * Formulario que permite establecer las preferencias
 */
function seleccionPreferencias() {
    $user = $_SESSION['usuario']; //Obtenemos el usuario actual en uso
    
    if (isset($_POST['guardar'])) { // Si se ha pulsado guardar...
        $theme = $_POST['combo']; //Obtenemos el valor seleccionado del combo del formulario
        setcookie($user, $theme); //Establecemos una cookie de nombre del usuario actual y con el theme que ha elegido
        header("Location: preferencias.php"); //Recargamos la páginca para mostrar los cambios realizados
        echo "<p class='perfect'>Se ha establecido el theme nuevo</p>"; //Mandamos un mensaje de feedback
    }
    
    if (isset($_POST['restablecer'])){ //Si se ha pulsado el botón de reestablecer...
        if (isset ($_COOKIE[$user])) { //Y existe cookie de usuario alguna con un theme
            unset($_COOKIE[$user]); //Eliminamos dicha cookie
            setcookie($user, NULL, -1); //La establecemos a nula y con la fecha a tomar por saco
            header("Location: preferencias.php"); //Recargamos de nuevo la página para hacer efectivos los cambios
        }
    }
    formularioPreferencias(); //Mostramos de el formulario de preferencias
}

/**
 * Funcion que cambia el valor del .css usado en la cabecera de cada página
 * 
 * @return string valor del theme a usar. Debe de existir en la carpeta css con el mismo nombre y especificados en el combobox de las preferencias
 */
function theme() {
    $user = $_SESSION['usuario']; //Si hay abierta una sesión de usuario...
    if (isset($_COOKIE[$user])) { //Comprobamos que haya una cookie de usuario
        $theme = $_COOKIE[$user]; //Obtenemos el valor del theme
    } else { //En otro caso
        $theme = "estilos"; //Se usa el valor por defecto
    }
    return $theme; //Devolvemos el valor del theme
}

/* FUNCIONES DE MENSAJES */
/*************************/

/**
 * Función que muestra todos los mensajes, ya sean privados o públicos
 */
function mensajesPrivados() {
    /* Conectamos a la base de datos */
    conectar();
    
    /* Lanzamos la consulta */
    try {
        $consulta = "SELECT * FROM mensajes";
        $resultado = $GLOBALS['con']->prepare($consulta);
        $resultado->execute(array());
    } catch (PDOException $e) {
        echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>";
    }
    
    /* Se prepara el acabado de la tabla a mostrar */
    echo "<table class='msg-tbl'>";
    if ($resultado->rowCount() > 0) { //Si el numero de resultados es mayor que cero (existen resultados a mostrar)
        foreach ($resultado as $registro) { //Por cada resultado como un usuario...
            echo "<tr><th>Escrito por: " . $registro['autor'] . " y enviado el dia " . $registro['fecha'] . "</th></tr>"; //Cabecero con los datos del usuaruio fecha de envio
            if ($registro['privado'] == true) {
                echo "<tr><td class='privado'>" . $registro['contenido'] . "</td></tr>"; //Si es privado tendrá un color
            } else {
                echo "<tr><td class='publico'>" . $registro['contenido'] . "</td></tr>"; //Si es publico tendra otro color
            }
        }
        echo "</table>"; //Cerramos la tabla
        
    } else { //En el caso de no existir elementos, lo indicamos
        echo "<tr class='centrado'><td colspan='2'>No existen mensajes que visualizar</td></tr></table>"; //Mensaje de feedback
    }
}

/**
 * Funcion que muestra unicamente los mensajes públicos
 */
function mensajesPublicos() { 
    /* Conectamos a la base de datos */
    conectar();
    
    /* lanzamos la consulta */
    try {
        $consulta = "SELECT * FROM mensajes WHERE privado = FALSE";
        $resultado = $GLOBALS['con']->prepare($consulta);
        $resultado->execute(array());
    } catch (PDOException $e) {
        echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>";
    }
    
    /* Se prepara el acabado de la tabla a mostrar */
    echo "<table class='msg-tbl'>";
    if ($resultado->rowCount() > 0) { //Si el numero de resultados es mayor que cero (existen resultados a mostrar)
        foreach ($resultado as $registro) { //Ppor cada resultado como un usuario...
            echo "<tr><th>Escrito por: " . $registro['autor'] . " y enviado el dia " . $registro['fecha'] . "</th></tr>"; //Cabecero con los datos del usuaruio fecha de envio
            echo "<tr><td class='publico'>" . $registro['contenido'] . "</td></tr>"; //En este caso solo se muestran los mensajes públicos
        }
        echo "</table>"; 
        
    } else { //En el caso de no existir elementos, lo indicamos
        echo "<tr class='centrado'><td colspan='2'>No existen mensajes que visualizar</td></tr></table>"; //Mensaje de feedback
    }
}


/* FUNCIONES DE VALIDACION */
/***************************/

/**
 * Funcion para comprobar si el usuario se encuentra duplicado
 * 
 * @param type $usuario
 * @return boolean
 */
function comprueba_usuario_duplicado($usuario) {
    if (!empty($usuario)) {
        try { //Preparamos la consulta
            $consulta = "SELECT * FROM foreros WHERE login = :login";

            $resultado = $GLOBALS['con']->prepare($consulta);
            $resultado->bindParam(":login", $usuario);
            $resultado->execute();

            if ($resultado->rowCount() > 0) { //Si existe ya un user con ese nombre
                return false;
            }
            return true;

        } catch (PDOException $e) { //En caso de errores
            echo "<div class='errcon'><p>Se ha producido error " . $e->getMessage() . "</p></div>"; //Capturamos el error y lanzamos un mensaje
        } 
    }
}

/**
 * Funcion que comprueba si la password esta vacia
 * 
 * @param type $password parametro de clave
 * @return boolean 
 */
function comprueba_pass_vacia($password) {
    if (empty($password)) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba si las dos claves coinciden
 * 
 * @param type $password
 * @param type $password2
 * @return boolean
 */
function comprueba_pass_duplicada ($password, $password2) {
    if ($password != $password2) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba si el usuario no esta vacio
 * 
 * @param type $usuario
 * @return boolean
 */
function comprueba_usuario($usuario) {
    if (empty($usuario)) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba la longitud maxima del login de usuario
 * 
 * @param type $usuario
 * @return boolean
 */
function longitud_login($usuario) {
    if (strlen($usuario) > 20) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba la longitud maxima del password
 * 
 * @param type $password
 * @return boolean
 */
function longitud_pass($password) {
    if (strlen($password) > 100) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba si el email no esta vacio
 * 
 * @param type $email
 * @return boolean
 */
function comprueba_email($email) {
    if (empty($email)) {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba la longitud maxima del email
 * 
 * @param type $email
 * @return boolean
 */
function longitud_email($email) {
    if (strlen($email) > 50) {
        return false;
    }
    return true;
}

/**
 * Función que comprueba si el mensaje no esta vacio
 * 
 * @param type $mensaje
 * @return boolean valor true false con el resultado de la comprobacion
 */
function comprueba_mensaje($mensaje) {
    if (empty($mensaje) OR $mensaje == "") {
        return false;
    }
    return true;
}

/**
 * Funcion que comprueba si la longitud del mensaje supera los 500 caracteres de largo
 * 
 * @param type $mensaje
 * @return boolean
 */
function longitud_mensaje ($mensaje) {
    if (strlen($mensaje) > 500) {
        return false;
    }
    return true;
}

/**
 * Funcion que utiliza las funciones anteriores para validar el usuario y mandar
 * los mensajes de feedback con los errores recogidos
 * 
 * @param type $usuario     Parametro del usuario
 * @param type $password    Parametro del password
 * @param type $password2   Parametro del password2
 * @param type $email       Parametro del email
 * 
 * @return string Devuelve un mensaje con los errores obtenidos
 */
function validar_usuario($usuario, $password, $password2, $email) {
    $error = "";
    
    if (!comprueba_usuario($usuario)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El campo usuario no puede estar vacio</p>";
    }
    
    if (!comprueba_usuario_duplicado($usuario)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El usuario " . $usuario . " ya existe, pruebe con otro.</p>";
    }
    
    if (!longitud_login($usuario)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El usuario no puede superar los 10 caracteres</p>";
    }
    
    if (!comprueba_pass_vacia($password)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El campo password no puede estar vacio</p>";
    }
    
    if (!comprueba_pass_duplicada($password, $password2)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El password no coincide</p>";
    }
    
    if (!longitud_pass($password)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El password no puede superar los 100 caracteres</p>";
    }
    
    if (!comprueba_email($email)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El campo email no puede estar vacio</p>";
    }
    
    if (!longitud_email($email)){
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El email no puede superar los 50 caracteres</p>";
    }
    return $error;
}

/**
 * Función similar a la anterior, valida el mensaje con las diferentes funciones de validacion y 
 * muestra los mensajes de error recogidos por estos.
 * 
 * @param type $mensaje Parametro del mensaje
 * 
 * @return string Devuelve un mensaje con los errores obtenidos
 */
function validar_mensaje($mensaje) {
    $error = ""; //Valor por defecto, nada
    
    if (!comprueba_mensaje($mensaje)) {
        $error = $error . "<p class='errcon'><strong>ERROR: </strong>El campo texto no puede estar vacío</p>";
    }
    
    if (!longitud_mensaje($mensaje)) {
        $error = $error . "<p class='error'><strong>ERROR: </strong>El texto no puede superar los 500 caracteres</p>";
    }
    return $error;
}