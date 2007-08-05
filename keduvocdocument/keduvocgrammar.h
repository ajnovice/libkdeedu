/***************************************************************************

              manage grammar parts (articles, conjugation)

    -----------------------------------------------------------------------

    begin        : Sat Nov 27 09:50:53 MET 1999

    copyright    : (C) 1999-2001 Ewald Arnold <kvoctrain@ewald-arnold.de>
                   (C) 2001 The KDE-EDU team
                   (C) 2005, 2007 Peter Hedlund <peter.hedlund@kdemail.net>

    -----------------------------------------------------------------------

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KEDUVOCGRAMMAR_H
#define KEDUVOCGRAMMAR_H

#include "libkeduvocdocument_export.h"

#include <QtCore/QStringList>

#define CONJ_SIMPLE_PRESENT    "PrSi" // I live at home  what you frequently do
#define CONJ_PRESENT_PROGR     "PrPr" // I am working    what you currently are doing
#define CONJ_PRESENT_PERFECT   "PrPe" // I have cleaned  tell, #that# something has happened

#define CONJ_SIMPLE_PAST       "PaSi" // the train left 2 min ago  when did it happen
#define CONJ_PAST_PROGR        "PaPr" // it was raining  what happen at a given time in the past
#define CONJ_PAST_PARTICIPLE   "PaPa" // I cleaned       tell, #that# it happened

#define CONJ_FUTURE            "FuSi"

#define CONJ_PREFIX            "--"   // definition of prefixes (I, you, ..)

#define UL_USER_TENSE          "#"   // designates number of user tense

/**
 * Class representing the articles of a language
 *
 * It contains all available articles of the language as QString
 */
class KEDUVOCDOCUMENT_EXPORT KEduVocArticle
{
public:

  /**
   * The constructor without arguments
   */
  explicit KEduVocArticle();
  
  /** copy constructor for d-pointer safety */
  KEduVocArticle(const KEduVocArticle &other);

  /**
   * The constructor with arguments
   * @param fem_def reference to a QString with the definite female article
   * @param fem_indef reference to a QString with the indefinite female article
   * @param mal_def reference to a QString with the definite male article
   * @param mal_indef reference to a QString with the indefinite male article
   * @param nat_def reference to a QString with the definite neutral article
   * @param nat_indef reference to a QString with the indefinite neutral article
   */
  KEduVocArticle( const QString &fem_def, const QString &fem_indef, const QString &mal_def, const QString &mal_indef, const QString &nat_def, const QString &nat_indef );

  /**
   * default destructor, deletes the d pointer
   */
  ~KEduVocArticle();
  
  /**
   * Sets the female articles
   * @param def const reference to a QString with the definite female article
   * @param indef const reference to a QString with the indefinite female article
   */
  void setFemale(const QString &def, const QString &indef);

  /**
   * Sets the male articles
   * @param def const reference to a QString with the definite male article
   * @param indef const reference to a QString with the indefinite male article
   */
  void setMale(const QString &def, const QString &indef);

  /**
   * Sets the neutral articles
   * @param def const reference to a QString with the definite neutral article
   * @param indef const reference to a QString with the indefinite neutral article
   */
  void setNatural(const QString &def, const QString &indef);

  void getFemale (QString *def, QString *indef) const;
  void getMale   (QString *def, QString *indef) const;
  void getNatural(QString *def, QString *indef) const;
  
  /**
   * assignment operator for d-pointer copying
   */
  KEduVocArticle &operator=(const KEduVocArticle& other);

private:
  class Private;
  Private * const d;
};


class KEDUVOCDOCUMENT_EXPORT KEduVocComparison
{
public:

  /**
   * The constructor without arguments
   */
  explicit KEduVocComparison();
  
  /** copy constructor */
  KEduVocComparison(const KEduVocComparison &other);

  /**
   * The constructor with arguments
   * @param l1
   * @param l2
   * @param l3
   */
  KEduVocComparison(const QString &l1, const QString &l2, const QString &l3);

  /** default destructor, deletes the d-pointer */
  ~KEduVocComparison();
  
  void setL1(const QString &s);
  void setL2(const QString &s);
  void setL3(const QString &s);

  QString l1() const;
  QString l2() const;
  QString l3() const;

  bool isEmpty() const;
  void clear();

  bool operator == (const KEduVocComparison& a) const;

  /**
   * assignment operator for d-pointer copying
   */
  KEduVocComparison &operator=(const KEduVocComparison& other);

private:
  class Private;
  Private * const d;
};


class KEDUVOCDOCUMENT_EXPORT KEduVocTenseRelation
{
public:
  /** default constructor */
  KEduVocTenseRelation();
  KEduVocTenseRelation (const QString & _short, const QString & _long);
  
  /** default destructor, deletes the d-pointer */
  ~KEduVocTenseRelation();

  QString shortStr() const;
  QString longStr()  const;

  KEduVocTenseRelation &operator=(const KEduVocTenseRelation &other);

private:
  class Private;
  Private * const d;
};

/**
 * The conjugation of a verb
 */
class KEDUVOCDOCUMENT_EXPORT KEduVocConjugation
{
public:

  /**
   * The constructor
   */
  explicit KEduVocConjugation();

  KEduVocConjugation(const KEduVocConjugation& rhs);

  ~KEduVocConjugation();

  /**
   * @return
   */
  int entryCount() const;

  /**
   * @return 
   */
  static QList<KEduVocTenseRelation> getRelation();

  /**
   * @param names
   */
  static void setTenseNames(const QStringList& names);

  static QString getName(const QString &abbrev);
  static QString getName(int index);
  static QString getAbbrev(const QString &name);
  static QString getAbbrev(int index);
  static int numInternalNames();
  static int tenseCount();

  QString getVerbName() const;

  QString getType(int index);
  void setType(int index, const QString & type);
  void cleanUp();
  bool isEmpty(int idx);

  QString pers1Singular(const QString &type) const;
  QString pers2Singular(const QString &type) const;
  bool    pers3SingularCommon(const QString &type) const;
  QString pers3FemaleSingular(const QString &type) const;
  QString pers3MaleSingular(const QString &type) const;
  QString pers3NaturalSingular(const QString &type) const;

  QString pers1Plural(const QString &type) const;
  QString pers2Plural(const QString &type) const;
  bool    pers3PluralCommon(const QString &type) const;
  QString pers3FemalePlural(const QString &type) const;
  QString pers3MalePlural(const QString &type) const;
  QString pers3NaturalPlural(const QString &type) const;

  void setPers1Singular(const QString &type, const QString &str);
  void setPers2Singular(const QString &type, const QString &str);
  void setPers3SingularCommon(const QString &type, bool f);
  void setPers3FemaleSingular(const QString &type, const QString &str);
  void setPers3MaleSingular(const QString &type, const QString &str);
  void setPers3NaturalSingular(const QString &type, const QString &str);

  void setPers1Plural(const QString &type, const QString &str);
  void setPers2Plural(const QString &type, const QString &str);
  void setPers3PluralCommon(const QString &type, bool f);
  void setPers3FemalePlural(const QString &type, const QString &str);
  void setPers3MalePlural(const QString &type, const QString &str);
  void setPers3NaturalPlural(const QString &type, const QString &str);

  KEduVocConjugation& operator = (const KEduVocConjugation& a);
  bool operator == (const KEduVocConjugation& a) const;

private:
  class Private;
  Private* const d;
};

#endif // KEDUVOCGRAMMAR_H