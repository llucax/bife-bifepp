// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef _BIFE_GHIT_H_
#define _BIFE_GHIT_H_

#include <string>
#include <stack>
#include "hit.h"

using namespace std;

/**
 * Group enabled HIT.
 *
 * HIT template with groups of templates added. You can specify a template
 * group. The group is used as a subdirectory in root template directory, so you
 * can group templates together. The default group ('') templates are stored in
 * the root directory.
 */
class GHIT: public HIT {
    // Attributes.
    protected:
        /// Group stack.
        stack<string> group;

    // Methods.
    protected:
        /**
         * Gets file name based on the blockname and the group.
         *
         * @param  blockname Name of the block to get the filename.
         * @return Block's filename.
         */
        virtual string getFileName(string);

    public:
        /**
         * Constructor.
         *
         * @param root    Root directory from where to get the templates.
         * @param postfix Postfix of the template files.
         * @param group   Starting group.
         */
        GHIT(string = ".", string = ".tpl", string = "");

        /**
         * Starts working with a new group of templates.
         *
         * @param group Group of templates to work with.
         */
        virtual void pushGroup(string);

        /**
         * Stops working with a group of templates.
         *
         * @return Last template's group used.
         */
        virtual string popGroup(void);

        /**
         * Gets the current working group.
         *
         * @return Current template's group.
         */
        virtual string getGroup(void);
};

#endif
