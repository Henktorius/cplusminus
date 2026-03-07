// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 13 "src/parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  extern int yylineno;

#line 54 "target/parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "target/parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_trailing_newlines: // trailing_newlines
      case symbol_kind::S_top_var_decls: // top_var_decls
      case symbol_kind::S_top_class_decls: // top_class_decls
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_method: // method
      case symbol_kind::S_params: // params
      case symbol_kind::S_var: // var
      case symbol_kind::S_type: // type
      case symbol_kind::S_base_type: // base_type
      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_end: // stmt_end
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_FLOATTYPE: // FLOATTYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LEQ: // LEQ
      case symbol_kind::S_GEQ: // GEQ
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_NEWLINE: // NEWLINE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_trailing_newlines: // trailing_newlines
      case symbol_kind::S_top_var_decls: // top_var_decls
      case symbol_kind::S_top_class_decls: // top_class_decls
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_method: // method
      case symbol_kind::S_params: // params
      case symbol_kind::S_var: // var
      case symbol_kind::S_type: // type
      case symbol_kind::S_base_type: // base_type
      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_end: // stmt_end
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_args: // args
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_FLOATTYPE: // FLOATTYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LEQ: // LEQ
      case symbol_kind::S_GEQ: // GEQ
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_NEWLINE: // NEWLINE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_trailing_newlines: // trailing_newlines
      case symbol_kind::S_top_var_decls: // top_var_decls
      case symbol_kind::S_top_class_decls: // top_class_decls
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_method: // method
      case symbol_kind::S_params: // params
      case symbol_kind::S_var: // var
      case symbol_kind::S_type: // type
      case symbol_kind::S_base_type: // base_type
      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_end: // stmt_end
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_args: // args
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_FLOATTYPE: // FLOATTYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LEQ: // LEQ
      case symbol_kind::S_GEQ: // GEQ
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_NEWLINE: // NEWLINE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_trailing_newlines: // trailing_newlines
      case symbol_kind::S_top_var_decls: // top_var_decls
      case symbol_kind::S_top_class_decls: // top_class_decls
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_method: // method
      case symbol_kind::S_params: // params
      case symbol_kind::S_var: // var
      case symbol_kind::S_type: // type
      case symbol_kind::S_base_type: // base_type
      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_end: // stmt_end
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_args: // args
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_FLOATTYPE: // FLOATTYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LEQ: // LEQ
      case symbol_kind::S_GEQ: // GEQ
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_NEWLINE: // NEWLINE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_trailing_newlines: // trailing_newlines
      case symbol_kind::S_top_var_decls: // top_var_decls
      case symbol_kind::S_top_class_decls: // top_class_decls
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_method: // method
      case symbol_kind::S_params: // params
      case symbol_kind::S_var: // var
      case symbol_kind::S_type: // type
      case symbol_kind::S_base_type: // base_type
      case symbol_kind::S_stmt_block: // stmt_block
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt_end: // stmt_end
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_for_init: // for_init
      case symbol_kind::S_for_cond: // for_cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_args: // args
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_INTTYPE: // INTTYPE
      case symbol_kind::S_FLOATTYPE: // FLOATTYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWOP: // POWOP
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LEQ: // LEQ
      case symbol_kind::S_GEQ: // GEQ
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_NEWLINE: // NEWLINE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: top_var_decls top_class_decls entry trailing_newlines
#line 81 "src/parser.yy"
      {
        root = new Node("Program", "", yylineno);
        root->children.push_back(yystack_[3].value.as < Node* > ());
        root->children.push_back(yystack_[2].value.as < Node* > ());
        root->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 873 "target/parser.tab.cc"
    break;

  case 3: // trailing_newlines: %empty
#line 91 "src/parser.yy"
                            { yylhs.value.as < Node* > () = new Node("Trailing", "", yylineno); }
#line 879 "target/parser.tab.cc"
    break;

  case 4: // trailing_newlines: trailing_newlines NEWLINE
#line 92 "src/parser.yy"
                              { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 885 "target/parser.tab.cc"
    break;

  case 5: // top_var_decls: %empty
#line 97 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("VarDecls", "", yylineno); }
#line 891 "target/parser.tab.cc"
    break;

  case 6: // top_var_decls: top_var_decls var stmt_end
#line 99 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[2].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 897 "target/parser.tab.cc"
    break;

  case 7: // top_var_decls: top_var_decls NEWLINE
#line 101 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 903 "target/parser.tab.cc"
    break;

  case 8: // top_class_decls: %empty
#line 106 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ClassDecls", "", yylineno); }
#line 909 "target/parser.tab.cc"
    break;

  case 9: // top_class_decls: top_class_decls class_decl stmt_end
#line 108 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[2].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 915 "target/parser.tab.cc"
    break;

  case 10: // top_class_decls: top_class_decls NEWLINE
#line 110 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 921 "target/parser.tab.cc"
    break;

  case 11: // class_decl: CLASS ID LCB class_body RCB
#line 115 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Class", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 930 "target/parser.tab.cc"
    break;

  case 12: // class_body: %empty
#line 123 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ClassBody", "", yylineno); }
#line 936 "target/parser.tab.cc"
    break;

  case 13: // class_body: class_body var stmt_end
#line 125 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[2].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 942 "target/parser.tab.cc"
    break;

  case 14: // class_body: class_body method stmt_end
#line 127 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[2].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 948 "target/parser.tab.cc"
    break;

  case 15: // class_body: class_body NEWLINE
#line 129 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 954 "target/parser.tab.cc"
    break;

  case 16: // entry: MAIN LP RP COLON INTTYPE stmt_block
#line 134 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Entry", "main", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 963 "target/parser.tab.cc"
    break;

  case 17: // method: ID LP RP COLON type stmt_block
#line 142 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Method", yystack_[5].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(new Node("Params", "", yylineno));
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 974 "target/parser.tab.cc"
    break;

  case 18: // method: ID LP params RP COLON type stmt_block
#line 149 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Method", yystack_[6].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[4].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 985 "target/parser.tab.cc"
    break;

  case 19: // params: ID COLON type
#line 159 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Params", "", yylineno);
        Node* p = new Node("Param", yystack_[2].value.as < std::string > (), yylineno);
        p->children.push_back(yystack_[0].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(p);
      }
#line 996 "target/parser.tab.cc"
    break;

  case 20: // params: params COMMA ID COLON type
#line 166 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = yystack_[4].value.as < Node* > ();
        Node* p = new Node("Param", yystack_[2].value.as < std::string > (), yylineno);
        p->children.push_back(yystack_[0].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(p);
      }
#line 1007 "target/parser.tab.cc"
    break;

  case 21: // var: ID COLON type
#line 176 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("VarDecl", yystack_[2].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1016 "target/parser.tab.cc"
    break;

  case 22: // var: ID COLON type ASSIGN expr
#line 181 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("VarDecl", yystack_[4].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1026 "target/parser.tab.cc"
    break;

  case 23: // var: VOLATILE ID COLON type
#line 187 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("VarDecl", yystack_[2].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(new Node("Volatile", "", yylineno));
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1036 "target/parser.tab.cc"
    break;

  case 24: // var: VOLATILE ID COLON type ASSIGN expr
#line 193 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("VarDecl", yystack_[4].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(new Node("Volatile", "", yylineno));
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1047 "target/parser.tab.cc"
    break;

  case 25: // type: base_type
#line 202 "src/parser.yy"
                           { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1053 "target/parser.tab.cc"
    break;

  case 26: // type: base_type LSB RSB
#line 204 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ArrayType", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); }
#line 1059 "target/parser.tab.cc"
    break;

  case 27: // type: ID
#line 205 "src/parser.yy"
                           { yylhs.value.as < Node* > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno); }
#line 1065 "target/parser.tab.cc"
    break;

  case 28: // type: VOID
#line 206 "src/parser.yy"
                           { yylhs.value.as < Node* > () = new Node("Type", "void", yylineno); }
#line 1071 "target/parser.tab.cc"
    break;

  case 29: // base_type: INTTYPE
#line 210 "src/parser.yy"
               { yylhs.value.as < Node* > () = new Node("BaseType", "int",     yylineno); }
#line 1077 "target/parser.tab.cc"
    break;

  case 30: // base_type: FLOATTYPE
#line 211 "src/parser.yy"
               { yylhs.value.as < Node* > () = new Node("BaseType", "float",   yylineno); }
#line 1083 "target/parser.tab.cc"
    break;

  case 31: // base_type: BOOLEAN
#line 212 "src/parser.yy"
               { yylhs.value.as < Node* > () = new Node("BaseType", "boolean", yylineno); }
#line 1089 "target/parser.tab.cc"
    break;

  case 32: // stmt_block: LCB RCB
#line 216 "src/parser.yy"
                          { yylhs.value.as < Node* > () = new Node("Block", "", yylineno); }
#line 1095 "target/parser.tab.cc"
    break;

  case 33: // stmt_block: LCB stmt_list RCB
#line 217 "src/parser.yy"
                          { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1101 "target/parser.tab.cc"
    break;

  case 34: // stmt_list: stmt
#line 222 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Block", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1107 "target/parser.tab.cc"
    break;

  case 35: // stmt_list: stmt_list stmt
#line 224 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1113 "target/parser.tab.cc"
    break;

  case 36: // stmt_list: NEWLINE
#line 226 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Block", "", yylineno); }
#line 1119 "target/parser.tab.cc"
    break;

  case 37: // stmt_list: stmt_list NEWLINE
#line 228 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1125 "target/parser.tab.cc"
    break;

  case 38: // stmt_end: NEWLINE
#line 232 "src/parser.yy"
            { yylhs.value.as < Node* > () = new Node("StmtEnd", "", yylineno); }
#line 1131 "target/parser.tab.cc"
    break;

  case 39: // stmt: stmt_block
#line 238 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1137 "target/parser.tab.cc"
    break;

  case 40: // stmt: var stmt_end
#line 241 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1143 "target/parser.tab.cc"
    break;

  case 41: // stmt: expr ASSIGN expr stmt_end
#line 244 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Assign", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[3].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 1153 "target/parser.tab.cc"
    break;

  case 42: // stmt: IF LP expr RP stmt
#line 251 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("If", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1163 "target/parser.tab.cc"
    break;

  case 43: // stmt: IF LP expr RP stmt ELSE stmt
#line 258 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("IfElse", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[4].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1174 "target/parser.tab.cc"
    break;

  case 44: // stmt: FOR LP for_init COMMA for_cond COMMA expr ASSIGN expr RP stmt
#line 266 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("For", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[8].value.as < Node* > ());   /* init  */
        yylhs.value.as < Node* > ()->children.push_back(yystack_[6].value.as < Node* > ());   /* cond  */
        Node* upd = new Node("Assign", "", yylineno);
        upd->children.push_back(yystack_[4].value.as < Node* > ());
        upd->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(upd);  /* update */
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());  /* body   */
      }
#line 1189 "target/parser.tab.cc"
    break;

  case 45: // stmt: PRINT LP expr RP stmt_end
#line 278 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Print", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); }
#line 1195 "target/parser.tab.cc"
    break;

  case 46: // stmt: READ LP expr RP stmt_end
#line 281 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Read", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); }
#line 1201 "target/parser.tab.cc"
    break;

  case 47: // stmt: RETURN expr stmt_end
#line 284 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Return", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 1207 "target/parser.tab.cc"
    break;

  case 48: // stmt: BREAK stmt_end
#line 287 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Break", "", yylineno); }
#line 1213 "target/parser.tab.cc"
    break;

  case 49: // stmt: CONTINUE stmt_end
#line 290 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Continue", "", yylineno); }
#line 1219 "target/parser.tab.cc"
    break;

  case 50: // stmt: expr stmt_end
#line 294 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ExprStmt", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ()); }
#line 1225 "target/parser.tab.cc"
    break;

  case 51: // for_init: %empty
#line 299 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ForInit", "", yylineno); }
#line 1231 "target/parser.tab.cc"
    break;

  case 52: // for_init: var
#line 301 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1237 "target/parser.tab.cc"
    break;

  case 53: // for_init: expr ASSIGN expr
#line 303 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Assign", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1247 "target/parser.tab.cc"
    break;

  case 54: // for_cond: %empty
#line 312 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("ForCond", "", yylineno); }
#line 1253 "target/parser.tab.cc"
    break;

  case 55: // for_cond: expr
#line 314 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 1259 "target/parser.tab.cc"
    break;

  case 56: // expr: expr OR expr
#line 318 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "|",  yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1265 "target/parser.tab.cc"
    break;

  case 57: // expr: expr AND expr
#line 319 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "&",  yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1271 "target/parser.tab.cc"
    break;

  case 58: // expr: expr EQ expr
#line 320 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "=",  yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1277 "target/parser.tab.cc"
    break;

  case 59: // expr: expr NEQ expr
#line 321 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "!=", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1283 "target/parser.tab.cc"
    break;

  case 60: // expr: expr LT expr
#line 322 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "<",  yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1289 "target/parser.tab.cc"
    break;

  case 61: // expr: expr GT expr
#line 323 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", ">",  yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1295 "target/parser.tab.cc"
    break;

  case 62: // expr: expr LEQ expr
#line 324 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", "<=", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1301 "target/parser.tab.cc"
    break;

  case 63: // expr: expr GEQ expr
#line 325 "src/parser.yy"
                     { yylhs.value.as < Node* > () = new Node("BinOp", ">=", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1307 "target/parser.tab.cc"
    break;

  case 64: // expr: expr PLUSOP expr
#line 326 "src/parser.yy"
                      { yylhs.value.as < Node* > () = new Node("BinOp", "+", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1313 "target/parser.tab.cc"
    break;

  case 65: // expr: expr MINUSOP expr
#line 327 "src/parser.yy"
                      { yylhs.value.as < Node* > () = new Node("BinOp", "-", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1319 "target/parser.tab.cc"
    break;

  case 66: // expr: expr MULTOP expr
#line 328 "src/parser.yy"
                      { yylhs.value.as < Node* > () = new Node("BinOp", "*", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1325 "target/parser.tab.cc"
    break;

  case 67: // expr: expr DIVOP expr
#line 329 "src/parser.yy"
                      { yylhs.value.as < Node* > () = new Node("BinOp", "/", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1331 "target/parser.tab.cc"
    break;

  case 68: // expr: expr POWOP expr
#line 330 "src/parser.yy"
                      { yylhs.value.as < Node* > () = new Node("BinOp", "^", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ()); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1337 "target/parser.tab.cc"
    break;

  case 69: // expr: expr LSB expr RSB
#line 333 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("ArrayAccess", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[3].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 1347 "target/parser.tab.cc"
    break;

  case 70: // expr: expr DOT LENGTH
#line 340 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("FieldAccess", "length", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[2].value.as < Node* > ());
      }
#line 1356 "target/parser.tab.cc"
    break;

  case 71: // expr: expr DOT ID LP args RP
#line 346 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("MethodCall", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[5].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 1366 "target/parser.tab.cc"
    break;

  case 72: // expr: ID LP args RP
#line 353 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Call", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 1375 "target/parser.tab.cc"
    break;

  case 73: // expr: INT
#line 359 "src/parser.yy"
          { yylhs.value.as < Node* > () = new Node("IntLit",   yystack_[0].value.as < std::string > (),      yylineno); }
#line 1381 "target/parser.tab.cc"
    break;

  case 74: // expr: FLOAT
#line 360 "src/parser.yy"
          { yylhs.value.as < Node* > () = new Node("FloatLit", yystack_[0].value.as < std::string > (),      yylineno); }
#line 1387 "target/parser.tab.cc"
    break;

  case 75: // expr: ID
#line 361 "src/parser.yy"
          { yylhs.value.as < Node* > () = new Node("Id",       yystack_[0].value.as < std::string > (),      yylineno); }
#line 1393 "target/parser.tab.cc"
    break;

  case 76: // expr: TRUE
#line 362 "src/parser.yy"
          { yylhs.value.as < Node* > () = new Node("BoolLit",  "true",  yylineno); }
#line 1399 "target/parser.tab.cc"
    break;

  case 77: // expr: FALSE
#line 363 "src/parser.yy"
          { yylhs.value.as < Node* > () = new Node("BoolLit",  "false", yylineno); }
#line 1405 "target/parser.tab.cc"
    break;

  case 78: // expr: base_type LSB args RSB
#line 367 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("ArrayLit", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[3].value.as < Node* > ());
        yylhs.value.as < Node* > ()->children.push_back(yystack_[1].value.as < Node* > ());
      }
#line 1415 "target/parser.tab.cc"
    break;

  case 79: // expr: NOT expr
#line 374 "src/parser.yy"
      {
        yylhs.value.as < Node* > () = new Node("Not", "", yylineno);
        yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ());
      }
#line 1424 "target/parser.tab.cc"
    break;

  case 80: // expr: LP expr RP
#line 380 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 1430 "target/parser.tab.cc"
    break;

  case 81: // args: %empty
#line 385 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Args", "", yylineno); }
#line 1436 "target/parser.tab.cc"
    break;

  case 82: // args: expr
#line 387 "src/parser.yy"
      { yylhs.value.as < Node* > () = new Node("Args", "", yylineno); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1442 "target/parser.tab.cc"
    break;

  case 83: // args: args COMMA expr
#line 389 "src/parser.yy"
      { yylhs.value.as < Node* > () = yystack_[2].value.as < Node* > (); yylhs.value.as < Node* > ()->children.push_back(yystack_[0].value.as < Node* > ()); }
#line 1448 "target/parser.tab.cc"
    break;


#line 1452 "target/parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -106;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
    -106,    12,    13,  -106,    11,    31,  -106,     7,   -11,    39,
      14,    51,    49,  -106,   -11,  -106,  -106,  -106,    14,  -106,
    -106,  -106,  -106,  -106,    56,    47,    64,    52,  -106,    50,
      61,   279,    70,  -106,    72,  -106,   279,  -106,  -106,    74,
    -106,  -106,   279,   279,    77,   505,  -106,    57,   100,   505,
     279,   379,    -3,   279,    48,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   -22,
    -106,  -106,   -11,   -11,    80,   505,     1,  -106,   -24,  -106,
      83,   400,    38,    38,    69,    69,    69,   547,   526,    55,
      55,    55,    55,   568,   568,   -13,  -106,  -106,   155,  -106,
     279,  -106,  -106,   279,  -106,    91,    92,     2,    90,    94,
      98,    99,   279,   -11,   -11,    32,  -106,  -106,   -11,  -106,
     192,  -106,   287,   505,    37,    14,    14,   107,   104,   279,
     255,   279,   279,   357,  -106,  -106,  -106,  -106,  -106,  -106,
     279,  -106,  -106,  -106,    80,   105,    14,   421,  -106,   106,
     312,   442,   463,  -106,   357,  -106,    14,    80,   229,   279,
     279,   -11,   -11,  -106,  -106,  -106,   120,   108,   505,   505,
    -106,  -106,   229,   279,  -106,   336,   279,   484,   229,  -106
  };

  const signed char
  parser::yydefact_[] =
  {
       5,     0,     8,     1,     0,     0,     7,     0,     0,     0,
       0,     0,     0,    10,     0,     3,    38,     6,     0,    29,
      30,    31,    28,    27,    21,    25,     0,     0,     9,     2,
      23,     0,     0,    12,     0,     4,     0,    76,    77,    75,
      73,    74,     0,     0,     0,    22,    26,     0,     0,    24,
      81,     0,    79,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    15,     0,     0,     0,    82,     0,    80,     0,    70,
       0,     0,    64,    65,    66,    67,    68,    57,    56,    60,
      61,    62,    63,    58,    59,     0,    14,    13,     0,    16,
       0,    72,    78,    81,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    32,    36,     0,    39,
       0,    34,     0,    83,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,    48,    49,    40,    33,    37,    35,
       0,    50,    71,    19,     0,     0,     0,     0,    52,     0,
       0,     0,     0,    47,     0,    17,     0,     0,     0,    54,
       0,     0,     0,    41,    20,    18,    42,     0,    55,    53,
      45,    46,     0,     0,    43,     0,     0,     0,     0,    44
  };

  const signed char
  parser::yypgoto_[] =
  {
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
       5,    -1,    -5,   -73,  -106,   -14,  -105,  -106,  -106,   -17,
     -49
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,    29,     2,     7,    14,    47,    15,    72,   107,
     118,    24,    44,   119,   120,    17,   121,   149,   167,   122,
      76
  };

  const unsigned char
  parser::yytable_[] =
  {
      28,    99,   100,    10,    78,    25,    95,     8,   105,   102,
      11,    12,     3,    25,    45,   139,   106,    30,     4,    49,
      19,    20,    21,    22,    54,    51,    52,   100,   127,    55,
     101,   128,     9,    75,     5,    23,    75,    16,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    73,   166,   124,    13,    10,    10,    96,    97,
      50,     6,     4,   100,    18,    54,   142,   174,    79,    80,
      55,   155,    26,   179,    58,    59,    60,    27,    69,    32,
      31,    34,    54,   123,   165,    36,    75,    55,    70,    56,
      57,    58,    59,    60,    33,   133,    54,    48,    35,   134,
     135,    55,    50,    46,   136,    71,    74,    60,   141,    53,
      98,   103,   147,   150,   151,   152,   125,   126,   129,   153,
      25,    25,   130,   154,   143,   144,   131,   132,   145,   146,
     156,   172,   159,     0,   173,   148,     0,     0,     0,     0,
     163,    25,   168,   169,     0,   157,     0,   170,   171,     0,
       0,    25,     0,     0,     0,   164,   175,     0,     0,   177,
       4,    19,    20,    21,     0,   108,     0,   109,   110,   111,
     112,   113,   114,    37,    38,     0,   115,    40,    41,     0,
       0,     0,     0,    42,     0,    98,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     4,    19,    20,
      21,     0,   108,   117,   109,   110,   111,   112,   113,   114,
      37,    38,     0,   115,    40,    41,     0,     0,     0,     0,
      42,     0,    98,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     4,    19,    20,    21,     0,   108,
     138,   109,   110,   111,   112,   113,   114,    37,    38,     0,
     115,    40,    41,     0,     0,     0,     0,    42,     0,    98,
       4,    19,    20,    21,     0,     0,     0,     0,     0,     0,
      43,     0,     0,    37,    38,     0,   115,    40,    41,     0,
       0,     0,     0,    42,     0,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    37,    38,     0,
      39,    40,    41,     0,     0,     0,     0,    42,     0,     0,
       0,   140,     0,     0,    54,     0,     0,     0,     0,    55,
      43,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    16,   160,     0,     0,    54,
       0,     0,     0,     0,    55,     0,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
     176,     0,     0,    54,     0,     0,     0,     0,    55,     0,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    54,     0,     0,     0,     0,    55,
       0,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    16,    54,     0,    77,     0,
       0,    55,     0,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    54,     0,     0,
       0,     0,    55,   104,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    54,     0,
     158,     0,     0,    55,     0,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    54,
       0,   161,     0,     0,    55,     0,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      54,     0,   162,     0,     0,    55,     0,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    54,     0,   178,     0,     0,    55,     0,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    54,     0,     0,     0,     0,    55,     0,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    54,     0,     0,     0,     0,    55,     0,
      56,    57,    58,    59,    60,    61,     0,     0,    63,    64,
      65,    66,    67,    68,    54,     0,     0,     0,     0,    55,
       0,    56,    57,    58,    59,    60,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    54,     0,     0,     0,     0,
      55,     0,    56,    57,    58,    59,    60,     0,     0,     0,
      63,    64,    65,    66
  };

  const short
  parser::yycheck_[] =
  {
      14,    74,    26,    25,    53,    10,    28,     2,    21,    33,
       3,     4,     0,    18,    31,   120,    29,    18,     5,    36,
       6,     7,     8,     9,    27,    42,    43,    26,    26,    32,
      29,    29,    21,    50,    21,    21,    53,    48,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    47,   158,   103,    48,    25,    25,    72,    73,
      28,    48,     5,    26,    25,    27,    29,   172,    20,    21,
      32,   144,    21,   178,    36,    37,    38,    28,    21,    32,
      24,    29,    27,   100,   157,    24,   103,    32,    31,    34,
      35,    36,    37,    38,    30,   112,    27,    25,    48,   113,
     114,    32,    28,    33,   118,    48,     6,    38,   122,    32,
      30,    28,   129,   130,   131,   132,    25,    25,    28,   133,
     125,   126,    28,   140,   125,   126,    28,    28,    21,    25,
      25,    11,    26,    -1,    26,   130,    -1,    -1,    -1,    -1,
     154,   146,   159,   160,    -1,   146,    -1,   161,   162,    -1,
      -1,   156,    -1,    -1,    -1,   156,   173,    -1,    -1,   176,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,     5,     6,     7,
       8,    -1,    10,    48,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,     5,     6,     7,     8,    -1,    10,
      48,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,    30,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    -1,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      41,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    27,    -1,    -1,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    27,    -1,    29,    -1,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    45,    46,    47,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    27,    -1,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    27,
      -1,    29,    -1,    -1,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    45,    46,    47,
      27,    -1,    29,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    27,    -1,    29,    -1,    -1,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      46,    47,    27,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    44,
      45,    46,    47,    27,    -1,    -1,    -1,    -1,    32,    -1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    27,    -1,    -1,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    27,    -1,    -1,    -1,    -1,
      32,    -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    43,    44,    45
  };

  const signed char
  parser::yystos_[] =
  {
       0,    51,    53,     0,     5,    21,    48,    54,    60,    21,
      25,     3,     4,    48,    55,    57,    48,    65,    25,     6,
       7,     8,     9,    21,    61,    62,    21,    28,    65,    52,
      61,    24,    32,    30,    29,    48,    24,    18,    19,    21,
      22,    23,    28,    41,    62,    69,    33,    56,    25,    69,
      28,    69,    69,    32,    27,    32,    34,    35,    36,    37,
      38,    39,    40,    42,    43,    44,    45,    46,    47,    21,
      31,    48,    58,    60,     6,    69,    70,    29,    70,    20,
      21,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    28,    65,    65,    30,    63,
      26,    29,    33,    28,    33,    21,    29,    59,    10,    12,
      13,    14,    15,    16,    17,    21,    31,    48,    60,    63,
      64,    66,    69,    69,    70,    25,    25,    26,    29,    28,
      28,    28,    28,    69,    65,    65,    65,    31,    48,    66,
      24,    65,    29,    61,    61,    21,    25,    69,    60,    67,
      69,    69,    69,    65,    69,    63,    25,    61,    29,    26,
      24,    29,    29,    65,    61,    63,    66,    68,    69,    69,
      65,    65,    11,    26,    66,    69,    24,    69,    29,    66
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    50,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    55,    56,    56,    56,    56,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     4,     0,     2,     0,     3,     2,     0,     3,
       2,     5,     0,     3,     3,     2,     6,     6,     7,     3,
       5,     3,     5,     4,     6,     1,     3,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     1,     2,     1,     1,
       2,     4,     5,     7,    11,     5,     5,     3,     2,     2,
       2,     0,     1,     3,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     6,     4,     1,     1,     1,     1,     1,     4,     2,
       3,     0,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "MAIN",
  "VOLATILE", "INTTYPE", "FLOATTYPE", "BOOLEAN", "VOID", "IF", "ELSE",
  "FOR", "PRINT", "READ", "RETURN", "BREAK", "CONTINUE", "TRUE", "FALSE",
  "LENGTH", "ID", "INT", "FLOAT", "ASSIGN", "COLON", "COMMA", "DOT", "LP",
  "RP", "LCB", "RCB", "LSB", "RSB", "PLUSOP", "MINUSOP", "MULTOP", "DIVOP",
  "POWOP", "AND", "OR", "NOT", "LT", "GT", "LEQ", "GEQ", "EQ", "NEQ",
  "NEWLINE", "IFX", "$accept", "program", "trailing_newlines",
  "top_var_decls", "top_class_decls", "class_decl", "class_body", "entry",
  "method", "params", "var", "type", "base_type", "stmt_block",
  "stmt_list", "stmt_end", "stmt", "for_init", "for_cond", "expr", "args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    80,    80,    91,    92,    97,    98,   100,   106,   107,
     109,   114,   123,   124,   126,   128,   133,   141,   148,   158,
     165,   175,   180,   186,   192,   202,   203,   205,   206,   210,
     211,   212,   216,   217,   221,   223,   225,   227,   232,   237,
     240,   243,   250,   257,   265,   277,   280,   283,   286,   289,
     293,   299,   300,   302,   312,   313,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   332,
     339,   345,   352,   359,   360,   361,   362,   363,   366,   373,
     379,   385,   386,   388
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2116 "target/parser.tab.cc"

#line 392 "src/parser.yy"

