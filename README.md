#  DWES - Tarea 3

## Enunciado:

 Vamos a crear la aplicación de un foro de mensajes informativos. Los mensajes tienen una particularidad, y es que pueden ser privados o públicos, por lo que dependiendo si accedemos como un usuario registrado o como invitado veremos todos o algunos mensajes.

Dicha aplicación constará de las siguientes páginas:

- **index.php** : Ofrecerá 3 opciones:
  - **Autentificarse mediante usuario y contraseña:**  Se comprobará que dicho usuario esté dado de alta en la base de datos (en la tabla foreros). Si el usuario y contraseña son correctos se creará una sesión y se tendrá acceso  a la página  **foro.php**.
  Las contraseñas están almacenadas en la base de datos usando hashing de una sola vía mediante la función crypt, por lo tanto para comprobar si una contraseña es correcta se deberá usar la función password\_verify.
  Después de 3 intentos seguidos y fallidos, se procederá al bloqueo del usuario.
  - **Acceder como invitado:**  Iniciará sesión como invitado, accediendo a  **invitado.php** , donde se mostrará un mensaje de bienvenida, login como &quot;invitado&quot; y la hora a la que se conectó (hora en la que inició la sesión) y un menú con dos opciones: tablón y salir.
    - Tablón: Accederá a  **tablón.php** , pero sólo se visualizarán los mensajes públicos.
    - Salir: Cerramos sesión de invitado y volvemos al  **index.php**.
  - **Registrarse:**  Accederá a  **registro.php**  donde se le mostrará un formulario de registro de nuevo usuario, solicitando login, contraseña y email. Recuerda que la contraseña debe aparecer oculta y pedirla por duplicado, y que el campo bloqueado será TRUE. Además del botón GUARDAR deberá aparecer también el botón VOLVER en el caso de que el usuario se arrepienta del registro y desee volver a  **inicio.php**.
- **foro.php** : A esta página sólo tendrán acceso los usuarios que hayan sido autentificados. Se controlará su acceso mediante sesiones (las sesiones almacenarán el login del usuario y la hora de conexión), y se mostrará esta información en todo momento. Esta página debe ofrecer un menú que permita crear un mensaje ( **mensaje.php** ), acceder al tablón ( **tablón.php** ), a la página de preferencias ( **preferencias.php** ) y a la desconexión del usuario. El tablón mostrará todos los mensajes (privados y públicos).
- **mensaje.php:**  Se muestra un formulario para introducir el contenido del mensaje y un checkbox que indique si es privado o no. La fecha y el autor se detectan de forma automática.
- **tablón.php: ** Se muestra el listado de todos los mensajes, donde se indica el autor del mensaje (login), la fecha de creación y el contenido del mensaje. Los mensajes públicos deberán tener un color diferente a los mensajes privados (texto, fondo o encabezado).
- **preferencias.php** : Esta página permitirá al usuario seleccionar el color de fondo con el que se mostrarán todas las páginas. Estas preferencias serán guardadas en una cookie. En caso de que no se hayan establecido preferencias el color por defecto será el blanco. Esta página también ofrecerá la opción de restablecer las preferencias (debe eliminar la cookie).
- **funciones.inc** : página que constará de las funciones usadas en la aplicación. Al menos constará de las funciones de acceso y control a la base de datos.

Esta aplicación hará uso de la base de datos &quot;foro3&quot; (cuya estructura se da en el apartado &quot;Recursos Necesarios&quot;). Esta base de datos consta de dos tablas: foreros y mensajes.

El usuario con acceso total a dicha base de datos será &quot;dwes&quot; cuyo password es &quot;abc123.&quot;. Las contraseñas están almacenadas en la base de datos usando hashing de una sola vía mediante la función  **crypt** , por lo tanto para comprobar si una contraseña es correcta se deberá usar la función  **password\_verify**.

Este usuario, como administrador de la BD, será el encargado de desbloquear a los nuevos foreros y a los foreros bloqueados por fallar 3 veces seguidas la contraseña.



**PARTE II:** **Auto-evaluación**

Por último, tienes que  **AUTO-EVALUARTE** , justificando si fuese necesario las notas de cada apartado. Para ello usarás la plantilla que se encuentra en el apartado de &quot;Recursos Necesarios&quot;.



**NOTAS IMPORTANTES:**

- No se puede hacer ninguna modificación sobre la estructura de la base de datos ni el usuario de acceso a ésta
- La entrega de la tarea consiste en:
  - A la vez que realizas la tarea, elaborar un documento de texto en formato  **.** ODT con una guía (muy resumida, no pierdas demasiado tiempo en esto) y capturas si son necesarias de cada menú de la aplicación, sobre todo para mostrar que funciona, usando **títulos, un sumario con índices navegables (** [**pincha aquí**](http://aplicacionesysistemas.com/indice-con-libreoffice-writer-video-tutorial/#more-198) **para ver una guía de cómo hacerlos o** [**aquí**](https://help.libreoffice.org/Writer/Creating_a_Table_of_Contents/es) **para la última documentación oficial)**.
    - El archivo .ODT debe ser editado desde LibreOffice u OpenOffice. En &quot;Archivo -&gt; Propiedades&quot; me debe dar una idea del tiempo que se ha tardado en su edición. Si falta el .ODT restará 1 punto.  **Desde el propio LibreOffice se debe exportar a PDF, lo que generará un PDF con índices navegables a la izquierda**.
  - **En cada apartado hay que apoyar la documentación y comprobar que funciona con alguna/s capturas de pantalla. ** Se recomienda alguna herramienta que agilice el proceso como [Shutter](http://shutter-project.org/) (Linux) o [GreenShot](http://alternativeto.net/software/greenshot/) (Windows). En alguna de ellas (todas las que se pueda), se debe ver la plataforma con vuestra foto del perfil (la foto que os aparece arriba a la derecha).
  - El fichero . **ZIP**  a subir en la tarea debe contener una carpeta llamada  **Apellido1\_Apellido2\_Nombre\_DWES03\_Tarea**  que contenga:
    - El documento de texto . **ODT**  explicativo y el mismo documento exportado a . **PDF. Si falta el** [**índice**](http://aplicacionesysistemas.com/indice-con-libreoffice-writer-video-tutorial/#more-198) **de contenidos &quot;navegable&quot; en el pdf restará 1 punto.**
    - La hoja de cálculo de auto-evaluación .ODS
    - una carpeta con todos  **los ficheros necesarios y el proyecto de Netbeans completo. ** Si el programa no es fácilmente distribuible (con librerías incluidas en la carpeta dist y con rutas relativas) y multiplataforma (carpetas con &quot;/&quot;) restará 1 punto.
      - En las propiedades del proyecto PHP de Netbeans, en &quot;Run Configuration&quot; debes seleccionar Run As: PHP Built-in Web Server tal y como se ve en esta imagen:  [http://i.imgur.com/y6K0UwS.png](http://i.imgur.com/y6K0UwS.png)

## Criterios de corrección

|La obtención de la nota de la tarea se hará según los siguientes criterios mostrados en la siguiente tabla:|
|---|

| **Puntuación Máxima** | **Criterio** |
|---|---|
|  Sin calificación | Tarea no entregada o en borrador. |
| 0  |La tarea entregada no se corresponde con lo que se  pide.El fichero está corrupto o no se puede abrir.La tarea se ha entregado fuera de plazo.La tarea ha sido copiada.La estructura de la base de datos ha sido modificada.La aplicación no se puede ejecutar debido a errores.|
| 4  |Parte de la aplicación no se puede ejecutar.La tarea se realiza usando Sesiones, Cookies, AJAX, javascript, etc que se trabajarán en unidades posteriores.|
| 10 |La tarea entregada y que funcione correctamente (que no corresponda a ninguno de los apartados mencionados anteriormente) será corregida según la siguiente valoración:|

Cada uno de los apartados se puntuarán siguiendo la siguiente plantilla:

| 1) Menú inicio. | Formulario usuario/contraseña | 0,1 |
| --- | --- | --- |
| Ocultar contraseña | 0,1 |
| 3 intentos máximo - bloquear | 0,5 |
| password\_verify() | 0,3 |
| Acceso como invitado | 0,1 |
| Registrarse | 0,1 |
| 2) Registro usuario. | Login no duplicado - Consulta en la BD | 0,2 |
| Contraseña doble y oculta | 0,1 |
| Email válido (controlar @) | 0,2 |
| Bloqueado | 0,1 |
| crypt() | 0,5 |
| Insersión en BD | 0,1 |
| 3) Menú invitado. | Tablón con mensajes públicos | 0,3 |
| Consulta en la BD | 0,1 |
| Mensajes con fecha, autor y contenido | 0,1 |
| Salir (volver a inicio) | 0,1 |
| Sesión de invitado con login INVITADO y hora de inicio de la sesión | 0,3 |
|  4) Menú forero. | Mostrar información de la sesión | 0,3 |
| Nuevo mensaje | 0,1 |
| Contenido inferior a 500 caracteres | 0,2 |
| Checkbox con privado/público | 0,1 |
| Fecha y autor automáticos | 0,2 |
| Insersión en BD | 0,1 |
| Tablón | 0,1 |
| Mensajes con fecha, autor y contenido | 0,1 |
| Mensajes privados y públicos de diferente color | 0,3 |
| Consulta en la BD | 0,1 |
| Preferencias | 0,1 |
| Uso de cookies - Matener preferencias en toda la sesión | 1 |
| Desconectarse | 0,1 |
| Cerrar sesión | 0,1 |
| Volver al menú de inicio | 0,1 |
| General | Conexión/desconexión y acceso a la base de datos. | 0,3 |
| Correcta navegación entre páginas. | 0,2 |
| Control de errores mediante excepciones. | 1 |
| Estética y organización de la aplicación. | 1 |
| Estructuración del código (uso de funciones, uso de páginas, inclusión de ficheros externos, documentación del código, variables intuitivas, optimización,…). | 0,2 |
| Impresión general de la aplicación. | 1 |

  |

## Recursos necesarios:

Al menos será necesario tener instalado y configurado XAMPP con Apache y MySQL arrancados, y un editor para php, por ejemplo NetBeans o Notepad++

Archivos Necesarios:

- [Script para la base de datos](http://www.juntadeandalucia.es/educacion/gestionafp/datos/tareas/DAW/DWES_14076/2016-17/DAW_DWES_3_2016-17_Individual__288632/foro3.zip)
- [Plantilla para realizar la documentación de la tarea](http://www.juntadeandalucia.es/educacion/gestionafp/datos/tareas/DAW/DWES_14076/2016-17/DAW_DWES_3_2016-17_Individual__288632/Apellido1_Apellido2_Nombre_DWES03_Tarea_E3.odt)
- [Plantilla para auto-evaluar la tarea](http://www.juntadeandalucia.es/educacion/gestionafp/datos/tareas/DAW/DWES_14076/2016-17/DAW_DWES_3_2016-17_Individual__288632/Apellido1_Apellido2_Nombre_DWES03_Auto-evaluacion_Tarea03.ods)

Aclaración: es necesario tener creada la base de datos de la tarea con el script que se aporta aquí arriba.

[Manual de php.](http://es1.php.net/manual/es/index.php)

Ayuda para el uso de la [ función crypt() ](http://php.net/manual/es/function.crypt.php)para la generación de hash de contraseñas.

Ayuda para el uso de la  [función password\_verify() ](http://php.net/manual/es/function.password-verify.php)para comprobar el hash de una contraseña.
