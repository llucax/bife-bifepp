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
        // Attributes.
        protected:
            /// Root widget.
            Widget* root;

        // Methods.
        public:
            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             */
            Fallback(string);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             */
            Fallback(string, Hash);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             * @param content Content of the widget.
             */
            Fallback(string, Hash, Widget&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             */
            Fallback(string, Widget&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             * @param attrs   Widget attributes.
             */
            Fallback(string, Widget&, Hash);

            /**
             * Destructor.
             */
            virtual ~Fallback(void);

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            virtual string render(HIT&) = 0;
    };

}

#endif
