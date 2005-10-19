/* Sample parsing with QT's SAX2 by Riku Leino <tsoots@gmail.com> */

#include "../elementparser.h"
#include "../element.h"
#include <kdebug.h>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 2) {
		std::cout << "Usage: elements <XML_FILE>\n";
		return 1;
	}

	ElementSaxParser * parser = new ElementSaxParser();
	QFile xmlFile(argv[1]);
	QXmlInputSource source(xmlFile);
	QXmlSimpleReader reader;

	reader.setContentHandler(parser);
	reader.parse(source);

	QList<Element*> v = parser->getElements();

	foreach( Element* e, v ){
		if ( e )
		{
			QList<ChemicalDataObject*> list = e->data();

			//Test: Check if the string-comparison works
//X 			if ( e->data( ChemicalDataObject::name ) == "Helium" )
//X 				kdDebug() << "Mass: " << e->dataAsString( ChemicalDataObject::mass ) << endl;
			
			//Test: Check if the double-comparison works
//X 			if ( e->data( ChemicalDataObject::mass ) == 4.002602 )
//X 				kdDebug() << "Correct mass found" << endl;

			//Test: Give me the name of the element
//X 			kdDebug() << "Name: " << e->dataAsString( ChemicalDataObject::name ) << endl;
			
			//Test: give me all data available
//X 			foreach( ChemicalDataObject*o, list ){
//X 				if ( o )
//X 					kdDebug() << o->valueAsString() << endl;
//X 			}
		}

	}

	return 0;
}