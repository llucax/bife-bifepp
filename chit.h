// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_CHIT_H
#define BIFE_CHIT_H

#include "ghit.h"
#include "hash.h"
#include <string>

using std::string;

/**
 * Cache enabled GHIT.
 *
 * GHIT with cache capabilities added. The templates are stored in memory once
 * they are readed and reused in succesive parse() calls, avoiding disc reads
 * overhead.
 *
 * @todo See if it's really usefull, since the OS is supposed to be in charge
 *       of disc cache.
 */
class CHIT: public GHIT {
    // Attributes.
    protected:
        /// Cache storage.
        Hash cache;

    // Methods.
    protected:
        /**
         * Gets cached file content.
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
         * @param group   Starting group.
         */
        CHIT(string = string("."), string = string(".tpl"), string = string(""));

        /**
         * Destructor.
         */
        virtual ~CHIT(void);
};

#endif
