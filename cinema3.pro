QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_hall.cpp \
    admin_main.cpp \
    admin_movie.cpp \
    client_main.cpp \
    client_movie.cpp \
    client_vip.cpp \
    database.cpp \
    main.cpp \
    signin.cpp \
    zhuce.cpp

HEADERS += \
    admin_hall.h \
    admin_main.h \
    admin_movie.h \
    client_main.h \
    client_movie.h \
    client_vip.h \
    database.h \
    signin.h \
    zhuce.h

FORMS += \
    admin_hall.ui \
    admin_main.ui \
    admin_movie.ui \
    client_main.ui \
    client_movie.ui \
    client_vip.ui \
    signin.ui \
    zhuce.ui

#RC_FILE = icio.rc  换个图标折腾半上午一直报错，服了

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sdufe.qrc

DISTFILES += \
    res.ico \
    山财大招牌.png \
    山财大招牌1.png \
    山财大招牌1.png \
    山财大招牌1.png \
    山财大招牌1.png \
    山财大招牌1.png
