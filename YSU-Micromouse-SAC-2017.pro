TEMPLATE = subdirs

win32 {

}
else {
    SUBDIRS += src
}

CONFIG(debug, debug|release) {
    SUBDIRS += tests
}
