// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_HIT_H
#define BIFE_HIT_H

#include "hash.h"
#include <string>

namespace bife {

    using std::string;

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
            virtual string getFileName(const string&);

            /**
             * Gets file content.
             *
             * @param  filename Name of the file to get the content.
             * @return File content.
             */
            virtual string getFileContent(const string&);

        public:
            /**
             * Constructor.
             *
             * @param root    Root directory from where to get the templates.
             * @param postfix Postfix of the template files.
             */
            HIT(const string& = string("."), const string& = string(".tpl"));

            /**
             * Destructor.
             */
            virtual ~HIT(void);

            /**
             * Parses a block replacing keys with values in the hash.
             *
             * @param  blockname Name of the block to parse.
             * @param  vars      Hash containing the variable names and their values.
             * @return Parsed block with variables replaced.
             */
            string parse(const string&, Hash&);
    };

}

#endif
