// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_STRING_H
#define BIFE_STRING_H

#include "hit.h"
#include "hash.h"
#include "widget.h"
#include <string>

namespace bife {

    using std::string;

    /**
     * Base String Class.
     *
     * @todo 
     */
    class String: public Widget, public string {
        // Methods.
        public:
            /**
             * Constructor.
             */
            //String(void);

            /**
             * Constructor.
             *
             * @param attrs String attributes.
             */
            String(const char*);

            /**
             * Destructor.
             */
            virtual ~String(void);

            /**
             * Renders the String using a HIT template.
             *
             * @param  hit HIT template to use to render de String.
             * @return Rendered String.
             */
            virtual string render(HIT&);
    };

}

#endif
