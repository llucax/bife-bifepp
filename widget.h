// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_WIDGET_H
#define BIFE_WIDGET_H

#include "hit.h"
#include "hash.h"
#include <string>

namespace bife {

    using std::string;

    /**
     * Base Widget Class.
     *
     * @todo 
     */
    class Widget {
        // Attributes.
        public:
            /// Widget attributes.
            Hash attrs;

        // Methods.
        public:
            /**
             * Constructor.
             */
            Widget(void);

            /**
             * Constructor.
             *
             * @param attrs Widget attributes.
             */
            Widget(const Hash&);

            /**
             * Destructor.
             */
            virtual ~Widget(void);

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            virtual string render(HIT&) = 0;

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            virtual operator string(void) const;
    };

}

#endif
