// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_TRANSLATE_H
#define BIFE_TRANSLATE_H

#include "../libbife/fallback.h"
#include "../libbife/widget.h"
#include "../libbife/hit.h"
#include "../libbife/hash.h"
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
             */
            Translate(void);

            /**
             * Constructor.
             *
             * @param attrs   Widget attributes.
             */
            Translate(const Hash&);

            /**
             * Constructor.
             *
             * @param attrs   Widget attributes.
             * @param content Content of the widget.
             */
            Translate(const Hash&, Widget*);

            /**
             * Constructor.
             *
             * @param content Content of the widget.
             */
            //Translate(Widget*);

            /**
             * Constructor.
             *
             * @param content Content of the widget.
             * @param attrs   Widget attributes.
             */
            Translate(Widget*, const Hash&);

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
