// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef _BIFE_HIT_H_
#define _BIFE_HIT_H_

#include <string>
#include <fstream>
#include <sstream>
#include "hash.h"

using namespace std;

/**
 * Hooks vs IT Template Engine.
 *
 * Hooks vs IT (HIT) is a simple template implementation, based on hooks
 * and IT template systems.
 *
 * @todo Implementar buffers?
 */
class HIT {
    // Attributes.
    public:
        /// Root directory where to search for templates.
        string root;
        /// Postfix added to the blockname to convert it to a filename.
        string postfix;
        // bool search_path = false
        // TODO - Para subclases
        //Hash buffer;

    // Methods.
    protected:
        /**
         * Gets file name based on the blockname.
         *
         * @param  blockname Name of the block to get the filename.
         * @return Block's filename.
         */
        virtual string getFileName(string);

        /**
         * Gets file content.
         *
         * @param  filename Name of the file to get the content.
         * @return File content.
         */
        virtual string getFileContent(string);

    public:
        /**
         * Constructor.
         *
         * @param root    Root directory from where to get the templates.
         * @param postfix Postfix of the template files.
         */
        HIT(string = ".", string = ".tpl");

        /**
         * Parses a block replacing keys with values in the hash.
         *
         * @param  blockname Name of the block to parse.
         * @param  vars      Hash containing the variable names and their values.
         * @return Parsed block with variables replaced.
         */
        string parse(string, Hash&);
};

#endif
