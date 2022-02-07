QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCLUDEPATH += ..
SOURCES +=  tst_testing.cpp \
            ../calculations.cpp \
            ../customlist.cpp \
            ../customtree.cpp

