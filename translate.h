// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_TRANSLATE_H
#define BIFE_TRANSLATE_H

#include "fallback.h"
#include "widget.h"
#include "hit.h"
#include "hash.h"
#include <vector>
#include <string>

namespace bife {

    using std::string;

    /**
     * Base Translate Widget.
     *
     * @todo 
     */
    class Translate: public Fallback {
        // Methods.
        public:
            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             */
            Translate(const string&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             */
            Translate(const string&, const Hash&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param attrs   Widget attributes.
             * @param content Content of the widget.
             */
            Translate(const string&, const Hash&, Widget&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             */
            Translate(const string&, Widget&);

            /**
             * Constructor.
             *
             * @param name    Name of the widget.
             * @param content Content of the widget.
             * @param attrs   Widget attributes.
             */
            Translate(const string&, Widget&, const Hash&);

            /**
             * Destructor.
             */
            virtual ~Translate(void);

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            virtual string render(HIT&);
    };

}

#endif
