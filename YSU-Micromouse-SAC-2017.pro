TEMPLATE = subdirs

CONFIG(debug, debug|release) {
    SUBDIRS += tests
}

win32 {

}
else {
    SUBDIRS += src
}
