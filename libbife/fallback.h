// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_FALLBACK_H
#define BIFE_FALLBACK_H

#include "container.h"
#include "widget.h"
#include "hit.h"
#include "hash.h"
#include <vector>
#include <string>

namespace bife {

    using std::string;

    /**
     * Base Fallback Widget.
     *
     * @todo 
     */
    class Fallback: public Container {
        // Typedefs
        public:
            /// Fallback constructor function prototype.
            typedef Fallback* Constructor(const string&, const string&, const Hash&);

        // Attributes.
        public:
            /// Root widget.
            string name;

        // Methods.
        public:
            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             */
            Fallback(const string&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             */
            Fallback(const string&, const Hash&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             * @param content Content of the widget.
             */
            Fallback(const string&, const Hash&, Widget*);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             */
            Fallback(const string&, Widget*);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             * @param attrs   Widget attributes.
             */
            Fallback(const string&, Widget*, const Hash&);

            /**
             * Destructor.
             */
            virtual ~Fallback(void);
    };

}

#endif
