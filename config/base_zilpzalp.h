#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

#define BASE 0
#define L1 1
#define L2 2

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

&lt {
    flavor = "balanced";
    tapping-term-ms = <150>;
    quick-tap-ms = <100>;
};

#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
        COMBO(q, &kp Q, 0 1)
        COMBO(esc, &kp ESC, 1 2)
        COMBO(z, &kp Z, 18 19)
        COMBO(b, &kp B, 19 20)

        COMBO(sdq, &sdq, 6 7)
        COMBO(tab, &kp TAB, 5 6)
        COMBO(quex, &quex, 22 23)
        COMBO(k, &kp K, 21 22)
    };
};

/ {
    behaviors {
        ht: hold_tap {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            bindings = <&kp>, <&kp>;
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
        };
        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        quex: question_exclamation {
            compatible = "zmk,behavior-mod-morph";
            label = "QMARK_EXCL";
            #binding-cells = <0>;
            bindings = <&kp QMARK>, <&kp EXCL>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        sdq: single_double_quotes {
            compatible = "zmk,behavior-mod-morph";
            label = "SQT_DQT";
            #binding-cells = <0>;
            bindings = <&kp SQT>, <&kp DQT>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
