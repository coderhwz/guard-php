dnl $Id$
dnl config.m4 for extension hellovigossguard

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(hellovigossguard, for hellovigossguard support,
dnl Make sure that the comment is aligned:
dnl [  --with-hellovigossguard             Include hellovigossguard support])

dnl Otherwise use enable:

 PHP_ARG_ENABLE(hellovigossguard, whether to enable hellovigossguard support,
 Make sure that the comment is aligned:
 [  --enable-hellovigossguard           Enable hellovigossguard support])

if test "$PHP_HELLOVIGOSSGUARD" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-hellovigossguard -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/hellovigossguard.h"  # you most likely want to change this
  dnl if test -r $PHP_HELLOVIGOSSGUARD/$SEARCH_FOR; then # path given as parameter
  dnl   HELLOVIGOSSGUARD_DIR=$PHP_HELLOVIGOSSGUARD
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for hellovigossguard files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HELLOVIGOSSGUARD_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HELLOVIGOSSGUARD_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the hellovigossguard distribution])
  dnl fi

  dnl # --with-hellovigossguard -> add include path
  dnl PHP_ADD_INCLUDE($HELLOVIGOSSGUARD_DIR/include)

  dnl # --with-hellovigossguard -> check for lib and symbol presence
  dnl LIBNAME=hellovigossguard # you may want to change this
  dnl LIBSYMBOL=hellovigossguard # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HELLOVIGOSSGUARD_DIR/lib, HELLOVIGOSSGUARD_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HELLOVIGOSSGUARDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong hellovigossguard lib version or lib not found])
  dnl ],[
  dnl   -L$HELLOVIGOSSGUARD_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HELLOVIGOSSGUARD_SHARED_LIBADD)

  PHP_NEW_EXTENSION(hellovigossguard, hellovigossguard.c, $ext_shared)
fi
