GDPC                                                                               <   res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex�	            �tn��=:�s��b�   res://default_env.tres  @      �       um�`�N��<*ỳ�8   res://graph/graph.gdns  �      �       /���{���0쨾G   res://graph/graph.tscn  �      �       )P�As}>4 �l�   res://graph/graph_node.gdns `      �       V,�g�����sXܻn   res://graph/graph_node.tscn P      $      RU~�σ5}�}�u`�   res://icon.png  @3      ud       A��3��{y�(`��   res://icon.png.import   �      �      ��fe��6�B��^ U�$   res://productions/camera2d_ctrl.gdns@      �       �C��\�M���B��5&$   res://productions/graph_test.gdns   0      �       �T�e��wR��<j��x$   res://productions/graph_test.tscn           �      ��-È'ذ�pY-&�    res://productions/warshall.gdns  "      �       �^�z�.&%�-��Mɉ    res://productions/warshall.tscn �"      I      MZm��V��d���z�   res://project.binary��      X      M1*�g����a5VuO   res://visualizations.gdnlib @2      �       ���Ȟ�J?c��!8q            [gd_resource type="Environment" load_steps=2 format=2]

[sub_resource type="ProceduralSky" id=1]

[resource]
background_mode = 2
background_sky = SubResource( 1 )
             [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://visualizations.gdnlib" type="GDNativeLibrary" id=1]

[resource]
class_name = "Graph"
library = ExtResource( 1 )
             [gd_scene load_steps=2 format=2]

[ext_resource path="res://graph/graph.gdns" type="Script" id=1]

[node name="Graph" type="Node2D"]
script = ExtResource( 1 )
 [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://visualizations.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "GraphNode"
class_name = "GraphNode"
library = ExtResource( 1 )
             [gd_scene load_steps=3 format=2]

[ext_resource path="res://graph/graph_node.gdns" type="Script" id=1]

[sub_resource type="CircleShape2D" id=1]

[node name="GraphNode" type="RigidBody2D"]
mode = 2
gravity_scale = 0.0
script = ExtResource( 1 )

[node name="Label" type="Label" parent="."]
margin_bottom = 14.0
grow_horizontal = 2
grow_vertical = 2
custom_colors/font_color = Color( 0, 0, 0, 1 )
custom_colors/font_outline_modulate = Color( 0, 0, 0, 1 )
align = 1

[node name="Collision" type="CollisionShape2D" parent="."]
shape = SubResource( 1 )
            GDST0   0            �  WEBPRIFF�  WEBPVP8L�  //� �dD�c� m��wG�����<`�x��(���$ `�H�d�%[�8���y��6{�㾗wo=̍�I�1���׶mE��m[������Q�ґ�v�����ffNpw3�{/�f[oI��} IEdf����{���W3[h�.B$D��>�p��@*� �� ���r��P���{Z�K6S�2-D� �6�>�(CG��L�;Pa��
|"}8�erT���9ώo3
�����N���q��y��l��Xi�JM�#KV�U3�z}��C�8-�鰌lJ�.ￖ7�X�k���ܗ�1��M��e:e_&�rWi �a�9�XMy�Q�mzcH3�h�I+(	���X�<{5�{��ݵ\3-j?��ܞ_��H�2�Ļ�&�1�`k��)T�I�T&b̧�2\z�8`�W�=�Q?���qRiu9�i���T�Do?y3_Sl��Qt�1���Z�������H=i����/.��0wp��a݆4g��آ�a�^B�������(�9Lk��z�&��K鱁����4�F�"n��`Q.��w��1=��u�^t��wh�Hj�@�<���)���K�{c�����t0b��"ɋz�i�J�JE�o�Q.F-�7���㝆���1F�.�C��J&!f}(���>R�e�f!�1m>E�;�b�q�|7���w�Z��7{��t_�j;}�[˃Xl�H*�ޅ�$��ٽ��@�˾��<�khCq��͆�iڡh��u�`�3�5ⲩ5^��|����܏�~��3�R�V�S(�<�hz��
m0bs�i��l�������)�u�����wM7���^�y��1�Cdx��hԵ^��#5�`{���� �N�楃�:�#/ؙt�0�H�~���c92k��֒��6+F�X��v�hw�\�ɺ��7������
W�ȴ���\l������mKFs��ˋ�.n��(�%���1���;Jl30��ډv��Dҭ��5oӡ����y���{���r�>��h�~��	��>�>D?������E��WW������5�Z�Xƅ=}�mM�3��_`)�%���L����z��d۬�мD���f)�@�U޽�^Tp��_�҆���ϱN�����j�|p��o����6�?��@����/-�/���a��t�ܵ�]}or��Q�й;4N��O/�J]�/�2��G��5	���7q���a�v���WH8B��K��Wo�ɖ@?xZ�����1�������͗���,�t�4�ҵJ�q��s�6�0\~��ε2�q�����>��]ܗ��LL�.>*�����s�R���v��Z�~����-�J���(���?;���凗�s���h�u���_~p�B�����L����3�+�Aت��t��-�f�·���gxg	tM)�c����m��u�>�$���H{��#��]���W/��z%�X&L*8�|껇���?>=%��D��ڌ��y�_�$��מh����6c�.�7�ʹ�s��W�>����t^t�����lmM�汒���������_t�k|M�3�]��U�l�qRV������p�g�s8n��%�<���Ӫ^U2��g���w'�	�8A��lK���EҰ{�m/h��!������j�K�9V��@��y�M�,���(r (,����{\|�������G��̛���c�odn�-���/r?���?���ϛ��
�~����v�?���c������+<]W�G�����v���D���b�;�hL��rO��a�9�<]Yqx���1&��S+G�� �P]���Փ���^�w�~zⶓ�9q�vWi�w3�f^���]�y�)9(D4�)G/����X�ǗX��*�8� �y� �ԁ��\��Ӌ_�U/����b�0^�P��"_���E<[>�ظ�o�8:��Yg��\T|o���	۹����3���g>t�2A���C&y�4Zh�K���<(�z{�g/����6��Y漿��7�����Q�u�h�O}��y����*�ԉưғ?OO��O**�3U,��<W�O�ጀ��՜'j��s�S�K���|�Q�텷e�"�놁\�Đ�f�p�AԽ~�ô�.U�ha)��%*h;8�1�!���V{���"V\[a��b<��^Njă�X*"�U�S����z�_/�(�HB	<Q�((���rX$��K�9*�>a�)�ـ�L�#O<Ė�	J0�qy� �`�P���K��E�Ɍ#^�h��������p�ӧɬ�I8cT��}�m�M�'9��"Q�^�Sfb`K��V� މ[��_[Ik�iQ��O����VlY��/����f��ty��7���������h2I�,��� ���}����p��5yH������ڋk�O����� �3�L���!U�� @0 Q���1�^ ���/2]HJDI��"�UR���q-`��u�H��R�-�D#2�\I�m%�9줴���i�lLJ[9��{T]��
��1�[�|z��,�6��Lu!&0o�b�4�H/V�1D�T( �?��Z�R�K���*f�,���65����L���Fr�e�@�Z���37�!���Pl��#�=��ȭi�tOf&���vɎ�������G�_�oxkw1ؾ�W'��'�a2
��g�I��1 �: 1Ґ6$�f�fbq�1;E��NM�0Q����zT�z�m��zʸV�� ��zpZ�H�!�jA<#�q�2g�!H06�X�[Z����1�=��״���1.�kkQZ�?� 1b)�ʪyԞ�O8vUz��I�$��gu.ev��r株�ec�� ��D�j�{d�G2 bY'C�� ��"�&�SD�,�/���V��H�EpZ(�W��/9��zU�c���]�m�6-yDyo:�Su�CZ󲋦��L�l0�΢�#g���H�F�F��'`��㏶~���/�r�s>%���N��h}l��[j�1�Ĉ�%��ߢXAg��Y�����m��sFC/ڔ J��<(��D�A��.#=� #���9��&Z����6�)u�e�����y���e)�
r���(�����f���L=K%��ڎ������d�#?���<�Pᦉ�&'���cn�Ly����,j!Sz��L�|T�R��#��"ub� -���B�AH�b�'a�@v��:n���>T %eXK$3��Ůc#F"�nm)��OB)&ܜ��'��Hp6�D	����ۋ�����`'Vځ�Z�� F�#�ݕ� �`��;��U�8na�/ggL
��G��	��{%"4�ڭe�kӦ����x8���K�{���[x�~w���<�(�B���"B�>J�̧;��V��9�`�no���޵o����jm�As	>�(��	����cN�sQγ��e)�w۹4+�A%�]�׏G�s��H%�f�":gʕlC(�}��H/��1|(�XAth"��jzε��V{�0.0g �¨�p$7�&lS�`�-�Ű\P���cۚ��F.�����A�K�f��mjcD�8�y;�])4��|z�K_���R��@��XA�� eWކ$��B��ո���/�tÏ��>W'򧊞�������v�g�S�a�	�/��a�T�ʒE��9��{���̮��ۛ �'>��?am�M86Y�[�̟�i6I�J��}?��^6�I�F��HX�O�{���d90w)T�6us���Q��l��ݩ���c��� ��V�d9��s>#ؽ2i��z��=>���y^rE�W����#��Ȱ3%d%�E>�'ѻ��|�B�C�k�B(;	7d���;fJU�p��=����ᙤ��H3ncG��q=��XʭR���x+���+F�n�$���/�_h�>�`�Ҭ����&��Zv'����:_v�Uo�j\�h�ד)���K����������i���#�AY�Y�U�dm��1�f,-~���{)} h��vp�����;�;[��@���9��N�_@�D��<p��^כw�!�م����K'u)�ä6�*G`Q(��Fj)���g��|�Bo��f�e� ��}l�P��N��C��=��}�8Ab�>Q��Z�H���)�)y��*හ�]�cT\�������k�/����pY) )0���k��t!����.�~���0�"�q?�8%��e�1�sF��c۲_�����v���s���� �9����N����y(q��o]?�����������9aYq�o�m�O�������t����c) �N*XK�8�B�=�/{ЂL�N1� EQ�a���w�B����4��/eچO�K<ݠ$��w{��3Y-���r����U6���u�h��F���5���Yl�cF̮�J�3v� �@��c�������LUԴ�����F�me^p݇�!��$�=K2�kO��X�rI���&���MA
�|27�[+҈��:��)���              [remap]

importer="texture"
type="StreamTexture"
path="res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex"
metadata={
"vram_texture": false
}

[deps]

source_file="res://icon.png"
dest_files=[ "res://.import/icon.png-487276ed1e3a0c39cad0279d744ee560.stex" ]

[params]

compress/mode=0
compress/lossy_quality=0.7
compress/hdr_mode=0
compress/bptc_ldr=0
compress/normal_map=0
flags/repeat=0
flags/filter=true
flags/mipmaps=false
flags/anisotropic=false
flags/srgb=2
process/fix_alpha_border=true
process/premult_alpha=false
process/HDR_as_SRGB=false
process/invert_color=false
process/normal_map_invert_y=false
stream=false
size_limit=0
detect_3d=true
svg/scale=1.0
              [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://visualizations.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "Camera2DCtrl"
class_name = "Camera2DCtrl"
library = ExtResource( 1 )
       [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://visualizations.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "GraphTest"
class_name = "GraphTest"
library = ExtResource( 1 )
             [gd_scene load_steps=4 format=2]

[ext_resource path="res://graph/graph.tscn" type="PackedScene" id=1]
[ext_resource path="res://productions/camera2d_ctrl.gdns" type="Script" id=2]
[ext_resource path="res://productions/graph_test.gdns" type="Script" id=3]

[node name="GraphTest" type="Node2D"]
script = ExtResource( 3 )

[node name="Camera" type="Camera2D" parent="."]
current = true
script = ExtResource( 2 )

[node name="Graph" parent="." instance=ExtResource( 1 )]
           [gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://visualizations.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "Warshall"
class_name = "Warshall"
library = ExtResource( 1 )
               [gd_scene load_steps=6 format=2]

[ext_resource path="res://productions/warshall.gdns" type="Script" id=1]
[ext_resource path="res://graph/graph.tscn" type="PackedScene" id=2]

[sub_resource type="Shader" id=1]
code = "shader_type canvas_item;

void fragment() {
    COLOR = vec4(0.2, 0.2, 0.2, 1.0);
}"

[sub_resource type="ShaderMaterial" id=2]
shader = SubResource( 1 )

[sub_resource type="QuadMesh" id=3]
center_offset = Vector3( 0.5, 0.5, 0 )

[node name="Warshall" type="Node2D"]
script = ExtResource( 1 )

[node name="Sidebar" type="Position2D" parent="."]
position = Vector2( 1080, 0 )

[node name="SidebarBackground" type="MeshInstance2D" parent="Sidebar"]
material = SubResource( 2 )
scale = Vector2( 840, 1080 )
mesh = SubResource( 3 )

[node name="Text" type="RichTextLabel" parent="Sidebar"]
margin_left = 10.0
margin_top = 10.0
margin_right = 826.0
margin_bottom = 210.0
bbcode_enabled = true
bbcode_text = "Hello World!"
text = "Hello World!"

[node name="MatrixParent" type="Position2D" parent="Sidebar"]
position = Vector2( 10, 400 )

[node name="VerticalLine" type="Line2D" parent="Sidebar/MatrixParent"]
points = PoolVector2Array( 20, 0, 20, 660 )
width = 2.0
default_color = Color( 1, 1, 1, 1 )

[node name="HorizontalLine" type="Line2D" parent="Sidebar/MatrixParent"]
points = PoolVector2Array( 0, 15, 825, 15 )
width = 2.0
default_color = Color( 1, 1, 1, 1 )

[node name="SlideControl" type="Position2D" parent="Sidebar"]
position = Vector2( 10, 312 )

[node name="NextPath" type="Button" parent="Sidebar/SlideControl"]
margin_left = 6.0
margin_right = 80.0
margin_bottom = 20.0
disabled = true
text = "Next Path"

[node name="NextK" type="Button" parent="Sidebar/SlideControl"]
margin_left = 104.0
margin_right = 157.0
margin_bottom = 20.0
disabled = true
text = "Next k"

[node name="NextSlide" type="Button" parent="Sidebar/SlideControl"]
margin_left = 183.0
margin_right = 260.0
margin_bottom = 20.0
text = "Next Slide"

[node name="ToggleFullscreen" type="Button" parent="Sidebar/SlideControl"]
margin_left = 287.0
margin_right = 410.0
margin_bottom = 20.0
text = "Toggle Fullscreen"

[node name="ResetControl" type="Position2D" parent="Sidebar"]
position = Vector2( 10, 352.071 )

[node name="Label" type="Label" parent="Sidebar/ResetControl"]
margin_left = 1.0
margin_top = 5.0
margin_right = 94.0
margin_bottom = 27.0
text = "Node Amount:"

[node name="NodeNumInput" type="SpinBox" parent="Sidebar/ResetControl"]
margin_left = 99.0
margin_right = 179.0
margin_bottom = 24.0
min_value = 1.0
max_value = 32.0
value = 20.0

[node name="ResetButton" type="Button" parent="Sidebar/ResetControl"]
margin_left = 184.0
margin_right = 232.0
margin_bottom = 24.0
text = "Reset"

[node name="Label" type="Label" parent="Sidebar"]
margin_left = 447.0
margin_top = 258.0
margin_right = 846.0
margin_bottom = 312.0
text = "Created by Christopher Besch (chris-besch.com)
Source Code: github.com/christopher-besch/visualizations"

[node name="GraphViewportContainer" type="ViewportContainer" parent="."]
margin_right = 1080.0
margin_bottom = 1080.0
stretch = true

[node name="GraphViewport" type="Viewport" parent="GraphViewportContainer"]
size = Vector2( 1080, 1080 )
handle_input_locally = false
render_target_update_mode = 3

[node name="Camera" type="Camera2D" parent="GraphViewportContainer/GraphViewport"]
current = true

[node name="Graph" parent="GraphViewportContainer/GraphViewport" instance=ExtResource( 2 )]

[connection signal="pressed" from="Sidebar/SlideControl/NextPath" to="." method="next_path"]
[connection signal="pressed" from="Sidebar/SlideControl/NextK" to="." method="next_k"]
[connection signal="pressed" from="Sidebar/SlideControl/NextSlide" to="." method="next_slide"]
[connection signal="pressed" from="Sidebar/SlideControl/ToggleFullscreen" to="." method="toggle_fullscreen"]
[connection signal="pressed" from="Sidebar/ResetControl/ResetButton" to="." method="reset"]
       [general]

singleton=false
load_once=true
symbol_prefix="godot_"
reloadable=true

[entry]

HTML5.wasm32="res://bin/javascript/libvisualizations.wasm"
X11.64="res://bin/x11/libvisualizations.so"

[dependencies]

HTML5.wasm32=[  ]
X11.64=[  ]
               �PNG

   IHDR   0   0   W��  <�zTXtRaw profile type exif  x��i�9������8V���>�{$#�d�U���e�����Xܱ�����������_�	1�TS��
5T���\�������ϗ��/��q���!�핳=�/w������s��q�����y�}��~{����-��h�����=���/rO���y^����o-����]��G�n`^w����!Ւ�ե�7K�4�+�Ӊ]�gƞ���M+���wW�aG��S8�E-z�P>h�Č�s˫7�{����v��qߘ~�Y�y(��i5��6��6��Q���7/?-r�����cK.~<<�������5�>\���^W��/@k=W��z��]�������&[����!��Tw�������\��gW���o�N��Ɇ���B����>��?7ȃǳ�v���E��y������z��H��B��W����B������y�e3�c�:�3F�z�5� ����x��j��̤��B��O���܏<��O�_�Z��O�~�x�Ʌ��?�|o����<�z�8~�����p��>`����\����A��sǏ�����7����Ь�Ǳ��>~~��G/<Ȟ>���_�~��>?)��(�c���~��}��{�ky�ֽ��5\��ƾ.d��w�ok�����y�Wp.�BM{�8u?��c�7.=n]^Vz?Q�ӵ������WJ�-?: ��j<a��zx��%0�z}z�����1p�	�����q�?0-���$�➮ŻEW}y����������������B5>w~l6��	[�<-��~��������<�`x��5���җ}�es����Z}Z��~8=yZ��|�h<]6�k�^���xo���>w��������^�'��������
�/b���9���w����g<������Ms^��O~����+/�s�?�s����y����}�+��Xԅ,/+�C͡�oo;��E������n��Me�y,�^*��fjQ>b��CO��Z�cz{x��p�����V�QZD�{}sC8��3~�N_�����S��'K�}�=_�^���)�����^f}�ޟ�>�k�����[9�W�&�'??�������Q���'Y7O:����
��km/���/��C{��EO�z��_��������W_���_�����>�;�ݯ�J�$�b�l��|��?�~���Ɨ��0����1>��3���?L�S��f�e'￿?��u�g�+�o����{����gg���E��;���W�惘�o���W��Ys1�_�����?-��]�A=��������pߺ�>�ٍ����^��R7��|��Y�)�������?��{�ܿ����l|�P����� �?;�;���[����7����~��/��w[h~�ݳ��m���/`��o^�����l�O��t���)�����W�5߹%%����t\�х~Z��ٹ@�����^��zY_.��t1��L�/c�]��^ �_ܠ|�P��~�����?OF�[�Ak��C�\ ��u�k�������Y��?;������A����Z����E����/vM����0����hK_/h~v���2��;F�ۅ�=�}�����k���1�ؑ�w;��w���Qy4�y�R�?N[|����G��?��l��-
{��Q��`�G���m�����Fz!�.$���S����ïZ~�u�ӵ��$5���Mд��m����׿˷ו�	�OC0����P�jZ�&��G�A��f���Z�)�t��=y��+���}��ɇ}�j��oޚm�<�+c
�Gԯ}�5�e���"1-]K�%^E�L��~�oA�����r�6.�|�^���ek���ײ�Z��R��֝tRAݤ}���j�s��=�G�T�>j�7?z�w�7�5�!�I�������M��m�����'n84kw�'��ۛs�������c������h�%!�{�(�
�^*;��?����K�͗��h���^�aTM�-?z�3����c��cBF<�UyO0?z��<f���{�� �@�-�Wş�U��eFe7��a�i0U8ʸ˂�<�͜X�ӫ������E�����sUe[6p���0�{X'7����y4�=Бx��2+��1er�M���>N��L.�vԈru:j��9�f�<xc��h������@�Q>���ߣ��.d�y��N)X�k��;3~M��RnI��E:7�Շ}rΧ
��T���.8m��x��T��&�O��%S��4�o70�춵�b�:7OuZbc	���\W�T��5���ϱV��m������
�����k\S �x�.�g��{d?߸g�^#[����w�o���:�Y�wn�\O�:Cp�ۉ�ܪ�������o� ���K����.�����K�`B���s�J���|�*�T�{�P�_��?��n�ʨ�g��9=��Z�x��w~6Ʃ�P���ݿ�
��?��8jޮ�=?��?�?�s�?�s�?�O_�����Hz��m������Ӕ�i�����ᑞ7���[��LM\*�oe�ĵK��bи�H{��Kf�T�#x���h�T�WG��~[���z�o������(֛���q�a-�G|ʻ����u�[B��K�*�95.&��A���<�_���(�Y���?u����*;�F����-ƺ�}���U~�b����ꮪ��w����h����MTu���h��)�v�sW��H����>Up���
q�]��m��v
o�{��].rơ~���y������A���'#���������r�g��k�_�E1�؞�O�o������o��%�'��qv�g�5?꯺�3_��x�Cy�Q?SQ?�P{�__�iϿ�9o�����e�Yvz�?;�N�����s��^[A˷ߍ�oO�o�#�����&��~�]���n��oU�
�F�x��?ZџL�=�?.|���O�ͬ���6�����B.��B.��B.��B.��B.��B.��B.��B?;P �TMvi�,?��bJ1��S�O^�Vǧ����V�I����2�x�[�`�}����`7^�_UH���4�tWJn���JPuO�eΩ��y���ֳ�=�o�x�%��s�ʿ��u��y\��9��8�vX�t�Vu�roJD}��h�(���=�k#�{b�\=�J�6����j뽲�#<?�r���&�;����]��r�'=��S�D������:��k��ϳ����@�oo��Iy�;��{ᤡǽ{W�o	���s>;���gUU���O���4J������?�sg��>�?���z�?k�.��B.��B��}ݜ��n��Ϲ�u��-:=a�c}2��i��7��-�)T���N�/nb�~������_m�P������	C�s�/�ϑ4������UGW|���(�p]1s�3����~�O�wx{�u��օ]>��������b���/���>�:^���	T����y}鰭���s
��`��2ʏ�����U�k^t׿��獧����;s�� TUi�����m�����ݹٯ���s�Ss��ϧT���?|����	�q�~�|=7p���>5�����޳��gz�Bb8_���@�׉��0M�2����A�*�
�9�~��7l���6�i��v���2{.�e\�����Ⳬnk�)m�n'4u��j���-�ܶ^Ü��<-/u���s��_�g���9|�ڷ�n����N{��[��8/�O��{����0��$isN�����%�k��3wgU<{Cn��y~�Y�k��X�0k�G���ek��5����XLeZ)X�sS�n�[�=/u�����t$p�թf����Z���*K"�9�XcK�ۄ�N9�x��}&ǜr�%��
N]bI%�Rji�U�kǚj�����l\����Z��z4=��K���g�Gy�QG�`�3� y�Yg[vaJ+���ʫ����Զ7%��ϻ��Ǭ=��ݿ�0k��5wfJ/��fϙ~�%��$jΘ0g�eƕ��:�Psv���i�d��E5g�jƘ����۾�θ{F5s�Լ�>͛��3g4uq澟������q��
��[�^���KX��ee���՘�����3��X��|Yj����<RZ�b��g;fZ�	m������5M�a��}'o��8V�L�:G��T�PVgp]e�k�Z��r�#_W7��v�C;�K��B�Sjsv�F" ?S뛹룸TW�t�j��K�+0:���&�r��x$�]H��Q��C�@�Khe1���-y�ls�qJ�����9ty0W3w�p��g�c�����jur���u���u��[φIk-睲�tu�<'�}h9�i[6�8x=]m��j��u�6�l�4ZM޾ihw�������Et���1W�T��W���J^	77z��=�bܜ��s��2(��<�00���ҳ��k{&�3�8�����\���`�W��
��"��fš}N�텋�����n��2�Hn��;WW�rLt*e�q�lTWk9�����SK��<1w!kF-eh�4$�<���e�f�wn,�:�U6ch�h������6ᴺ�+�wa��efҦ��;���km���'S�ܥ�K1��d	o�YK*�������c�	;�s5>�P����ɯ�,����3�!�)0Xu�"f�vN�D�>���O׵G�.�JM�G`�2v��DZ\��>F�lY!��5�" �W=N�sl�%��1�;�	�)<p�^H�v��x�G4*bU�$��fq���ht,�Ҁᑁ�v���2�OP@�i��Y�f����8\�n�mX�^�B�����c��a�tu�̎^a���B�nm�]af����[:0�0h�ʱ��woK9�uk���غdbq`�]��a�����L�:��W����� _�KV�����Y-� 'v�`y,�p6\Q�	���֬����ě��(M��� �mӚ��'�� w��G��*��=�s�_!��=�^�`Ŗ�h��h�`,`ڨ4��A�С�^e�-Ƃ[�a/����r#vT��$WK�9��Ə9���F��D�>Q��O�3�,Hxr
X:� 1�De7��-B�d��d��<"�/�i�\���v�iO��Yg
X�.41����2��������,�u V�B�+�!Xx������/���'��@�F��`��^{�.��r#1�t7o%�(���׺6��X�/�7�U�\�g�"^�a�F|�x�s+ ��PV�̔|�/ ��hΝ���p��gm���Jhk��;��@�h�9�p l�!�f@���^�L>��:8������1�ʂ��q�0n��l[�p��)Z(��7�SM��l́�	q�'��zA�� �s
�Ho	�Hދcb|�ã�h�8�	y~���B�}+ܴ�=�ؖռ�F;dm\���ZJ��nh�/ÿrm\�{'G��A���=2�>���jR��5��:!��r?��>�����>��1ń�1v�:�ܹP�&��E'*0F�@�ML�/�kFOL��I����_\���ho�d#���s��a�ܕY����D����l��qҊ�]��<�;�13c�}Lb�bw`':�Apｂ�*D���T˶b.&Km���!H5aQNή0)p<���#�0��|Y6�&�'����m� Ə�x�'&a�����শ7Ǎ�|����L~�`���;g&���}3��Yo�#��[G��z� Qgq���@Za]�X	@ n௠@ĺ	6[�/>�BUZ��W�i�tlnv�.Frқ�j8)������!��[&���$0Sp������HZ���J �z=��S��1�d'*�}��@1�t��h� 3b�����06x�e��/:a��_�Q�����t,1&x �
�d�1^��'uzC(�%�N�$��d�E�Ea�8����݀4 �"PTn3��Ȩ�wA!x�ԭ�9��	�#�K����z �?�����wmM�M_� 	������p\�IK�̿�J��%T6
c��	H9唅������Z!�%")A(6��s�	:��T7�7#��U uE@��	��yz,�����J�hQ������v�s�U7� /r��V xm(���H�y!H���2�Ν1|�$� ��0�Q�P8DX�)("�&N�!� ^�F�֐�t^݂�]��ᒙyL�s�-��$t+��g����@!*�?P��ѵ����@ o3�1��^���P���V�^�;�,�|R��Qt�'��[od� XWd��x	��n'&Ch����-P��qA3(*h�[�$.��
8�ԧ*(j�J��*i��&��O�л�`C ��{�\���Z�Ap��'�D��Dp̫i"�=<��BNcy�Áv\(ӻ���� ��q&TvN\6�'��.E�~\Z�-���T>��9��A\q�.�ЃF4��.u��N�	'Z��u��d�\�:e��MhC�SdJ�A?�.��)�iJZ[-v}85���c� �z?;<��5�AR�fIg�X"�)�g�T�1-�0�,"�:�<��vA!^��
���l�n9��ż-���n*a��\2�G�g?u+اP�1�+q�3���	�j�����/�=c{D��P��<\	rhDm�$�&���0�ₛm�$�䂆���:�E�"�p�p�I�$�bAB=�aF�c�hMHJ"n�b1��r@� � �L�x񕠅���P�����b�/�[�`���:AG�^��p�b����r{ �IH��@�+E�a���ǧ*�o�q���%�D#���
j�i�9���zx���vt���w���(�Udiטi�@8�-�q�v";�� ��Uhx�Z�2F:�uC0���ag`�h��=���@ː�hĹ���Ɛ�M`��7ʷ&�+�qrR>�D�N�Q�Gl�1������5��'�=C�B�J�P��Z�{�7���5���.��,/���
@�ޮn�V���%�*�l�l�z]�n+YG���h����a>�5S���2�CeP��P<���C`-��撎zȀÑ`����8�?��:�lO�a}0x%�o�[X̦e�ZT����T��}[�B9o4.�|x~fbdFX2]Q�S�1�||a����V|!jh���}��	��|EM��u��_G7(�'+��
�fDJBA�L��P�m�Dx�,<��{�G�%����.�8WI֫�� �Y����*P)��M��}����64I�	��h���-�C���jp`�4�V��0����m	�H�r� ;�2����Ϲk��1d4�2'/ e��3r�8D	�����0	��R�(�K�yk���������Hd�2;�i	.�4�Y�
�D�)����j�� ږl�}�+z��j�`�#:bIB^<re��U�7��E�a�h�~+q�q�8���t���c��x	9�zo����1EJ�ӧ�,8��[i ��̲�>�.�+\Q�%:L�y!! �C� F�� rkx��ۖ�a��y���P�B�����1�5���m�^���M��g��U�+�����������~\Xh@� ލUJt�:��ڦ�D�E�&T.� �:����,]�k��ݺNb��v��ʴ�R��j��V�*+7\0�i��\���$�C��qt:c��Q-�Ko󒖐�h��p (+�FЂ�`3%|� �ݴ<�4�B\M@�D��|���W��g��V�PkA���7\�*S�p���1V\;�k��M
�V�U���	��C%"�Q����Sj:3ذ6�?�j��B��*��ŧ�d,ȱ�bUh�BH<΁��l���Ԩ~�#0��)
x�-�R�4�!N	be"RZ��̣�!2�ـ�se�0"(RםGb�~p��<tN3�g��"0de��ɖ�u%���@�&b�k�ι>GG2
X�ꫥk��r�6@����c��+�B��}hY�W��!! \"<�gBX��C�����/Jy p�a�RՅhT�y���K���~0]�m^Di��ybɀ6�N��0�U��f�bx�
]�6b�bJ�}HMh����6*"k�^�5NYO��H	��c�a�NKs�8p� �Y�7p�0��03���G��Ғ
bџ�x1W���ȶR�~L�ܒF9�/�k�q�Y�a^/�Ӹ~^���7S2^0� ֮l���(!vD/*Tv�&�V���d^�穽-��3��74Bׇ�#��6UI��$D[j!��C� ,�:Z��I���r�;M-91��Tu6�H�����n8�=���B'�Ł�`��DR�� ���c�|CtnZ�W|�R͗�b�d1t���2��{(N���t����e��k�BI��ݾ�&r��E�}+Z�#������S\�O�;%剧��F���ڵ�!_8|�g�ܩz	�
�C*@�*)��S�+Ï�{�������T)��	��` $����x�z%����Nye���E*�*�s�%ŢR"!�3cF�vaT�@lA�Վ�:�^l`�\|��j��9�����Hu�$�O��iB�tf�U|������R���hۧ�E��k�ٞ��N���!��P%���qC���k8Ư�; �;)��G�-�����¸�"#N�##Hׂ25NصC/"������̼"�$a�vx��e%��q��V�q 즗I�z�+ߙ��!�+��:�և{��L&!-�m���4�4ީ9����OB�T��#��Q�9���6;tg�tj�N���*G�l��$
k� nGH:���7�����b.�DB����v�ap�+�=�U�GǬBa����)���/b/�F�=Y~�0#g��!�k寴t�Nk�N��N�ePư��ܾ��� �cb��e��� �.g��p�BK����W�A�=,{J��@f������h@�19&�ԧg�0�P +,�C���-F΂I2C�9�uV� �tp,����u8V^����5� A	;U�I���ԈY�J"�ox��j��Y-��|��>�Nh�	D~[�̐l51ى֣_���[{2��������]���t]��Ђ+�qu4`A����{��=�a/QDc!�<U��U�3V�䧌�n.<�C��@�èC��?A�h[G�1[DD.�:n��Z��t��/#�-�ߔ#Q��ThRu���dW'���#�����p��ءY~4z�]��^J-��.�|�V`ֹ��諌!B0���(�5$��)bZ/Ϯ�^�F-z&�����ժ��|���"j�6L��H�*A�[�C�a1$:$Ã�)jեh	69D�I�^�!Wa ��撜��pA��?��'u���pC�JW򂉍̫׺a>�q�@�rBs �K�s��S����������=G��iT?c╚������մMLyXK���KT��4�:�^�B*���q@���:�%(ؔ�Ҋ��=��K���`X�&�����a��3�u*�Ac<�;���|�ec�`?p��=.���y^^K`�|����p����*!E�D9-�Y�sʤ"}����U��,p�s��gׇ�.�ES�%7����#b��4��Mx��0B���?E�%��ҡR��Mp3.tB�[��.�S�9�0���{��`'�@kK�S&� Ϊ�V�4��s�Ƭ�&�Qh�[�rO�r�zj�P�3�,�D�jڪpq/�"
I�E��l�����D2�T������EQN���$�����b�1W\��1� SڕpR�r�u�������s.�5T%j*�Qvs'�.�� �n�0�%��R`�[�Q�HXPi�= ^Ĥ����ZB�_����5�����,8�xֺ����(iQҶ_(ͼ))�2r� ���f�.�ϲ6�r���ʱ��ĳ�-Kҹ��I�q���hPk.���*�����h���{A��Է��O@'�K���^�W�ٝ"�r5.�6��T����*T@�Db���է�%I�����(��V�z`���C�(�C�Aa�3>�T��)��#M���'kW!�]�u !��]m�C��H;+��ȴ(w��b�Fhr=Kț'�K�ö�5�n�y�/cl��GdF������R����w>X:� -��L� �K)"�n��j��p���Y�pJb��A:'N��>�q�=1Y�;���.�5�UT�O
�rA/h֣��~'=�S���T_���e���/9Z�IBSyO���`70Z$Cer`�-���q�A7�LOm��
�$���]��i��* t4�8R��(���p�^�'���S$�%+	R~�N3%���a� g@톨o�0�Y�vʔ��i���)�΁��陈�b�t
F�Po�I������0��c^Jp~T� 
)z��TO5�M�4�Y�9O�	x�E��-Y��nh������z�Q�9��*dZt8)+�3`�8�]�{�)�J�^ qu:����E	�Sۂ�����j�|;��uT2{
���YEy9��/�&�$�z����N���b��S�&�עθ��wf�zp�,Y��K��Z��y�S|Msa��k�������y���C���3�Ą0���Wz��G��8	�]�ߊ0��e)j�W�Es7�ET�R��A�:28�ʠ�p���b�0O�d��>�E�5�J�U��$���+F�М��]��R��p���Q��]�! �����A-$5�B
��Um�tnHȃ�I��F�\�C˘^�U�K�q
�k��c/�͊�z�rR1�F�T�d�֍^�0\,�zJs��Ȁ���U��0��T-�IQK�8V���(>J���ᴠ�-��,�h�^�1U2��i&�ժ���kiցG:��k��P�|�'�s�;�V�_7�/�X�
�9'���j�(�y��+Uv`�ɦY՝!.���it��i+TNVs44Z�����\��Ϫݒ`��eB_�A�B��[U������qWLi���X�
p�:��7�{�.1�ץ��� �B�}�7�U�����US����|���!K���$��� ��4�>�Eaf������))p�h7�8�2uj�ة2ZK3GC&���2^Zi~y���
�ґ�͝&B(������bũ̠-�
OB�{��Tv՞R�%+�����6�اAp6�9�O���ʳ��R]�g֒��p�T����u+���;�/��=U1�p!^��ƮzP+-@?�Ϊ[5A���5��T}�TV���PN)��Z��1����Y��	g�ъ��%ƅ�Y��*(3������)�%�#'�{��X��ԭ+�ɬ!����Ȫ�;�"mxe%Zb&
1]ҧ�h��^JM��@�����m<Z���)�ߔ�>TrB���Y�U� �u�$��Q����A���Y�t���S9Ҕ`ZV��c��`RD��e�{���ȟ��x)�Ku�gE�5��aѲ���ET4A"J�z��C۸��&��F���:e�pX�]V�GA�I�띄��t��6�E����ɏ�"T gR&$ՏG��6�Y�I;yF=��bG0g��j����ul��I�I�Ne= �IN�FU�u����`�P�^�8�g�:Ɗ8�%a�7�`����X�r~�8E�ӂo��j,j���'��F(�n�,���vcxZ��Tz����� ��YH:ҥ�v�/�>,_�i�s$��~e��V)i�~6��`�>�~u��U���I���zի��2�Ϗ!l"��i#q��X�z�T�޵*��r�>TI:�UO� �֊%����djH�ƥ�mr��u'�����vNIJ��ܢN�� !|B�$��:�H.���u��+{��;�i�m.���O/X̣~ʫ0��,�*8moh?�x�� {�GN����JL�\n׊qgz��T����f��@���[�=`V�����kv�-�T�*��A�
.�먂Gw�S?3��H�aa��"2�B4��PiU�ాg�M>��v�ܚ7���=�����!�~�R���PɄ`y8,���ʣZ���'k=�6p�ڐ�Y���I��K��,���� `,�?�pmx2�d�N��g��y#�xW�A��2�;<'��y������W���ZU*A�)� �P9�p{��Ũk��+�*�Sz�%�瀿5�:����[��G��ZU���y��9*��r�S�����D�yu���KE��j��5��V��9Ic���W�lx��(Q�v6�`ow�LU�,�T�ʮ���M�R�BB]��Q�M*6�Bʏ������D�5�z"~B¶�,�۟�
����c�-Z�ժ�x�T<D٬�WLE~�CT1JS���ܒ��<Y�Rcת0AB�@+;]�p�@]�hɥ���y�R�6�.�
G�׎���=�dD h�U1p���$L��0/��kץv���!�Q-n�����Si!��FV���ϸ�n�w�ޏp
e��P?/��	ǰn�uY��>�N�	2 ����[�ntb|�Pq8�6�uB������w����ݢ��R�W���$jg0�U�݋�|4N-���vk�Y�]��;������>�8����x��hi��v��3��,k_D��1��q6!��#�����	{>�ew�F���o����z?��S,T�n��㐪r��]�BEBZ��]j�d :�K��`�rI���g�'E��4�kr-B���� ����P�<�sy)�t�7�;�5�b��V+�*�21�uU+�&�����K��Eզ�\Xe�/Jh^�ĉ2��A	rH
�.�!�kP0 E|J�JD��~=�Z�� 4L�@ZU�}���CF��%�\�CF�T]���gF_q�F�
8a��`�>�,a���,�`R^�%���\�u��S�J��n/Q7�!�P�]���5��E�����{'�����a��Ƨ`b�B��aO"��/&s".SOT��je����� 6��S�2��A��O�6�Z9��Ʃ�X��n�,�Q]���i'{��G�. �����5"�oUm�a��SQ�o`�2X�U�߰(�J@�M��Tg}��-�hY���X��@�T}�n0����E&n�d�8�)�$\��
�,(,�L�g�:P@{�Q�(I~�U�����k���;�$��rA��Yh`�(1�*/
JG�gK���:�}S����p{��j�Mah��vhA����J�xx�I�ï�
�C�d�Ze��B챣�R ��K��g��/P��y���
����=ZC������x2|2V^�4�=v~��^��J|��Sg_���$BC��;�ss��nlުnVi�T�R��i�qͩ*����S�un�-��0�d:���� B�� �$���`� ���q��d�*�,�S*����:z,�E`��:HZ�!/����8��]hj�H����Tx�u��*�S�xd�C�p�n�̕piO �w�'��B�QB���_|\
_f�����%"��L��CR�(�R�}/𕳾ו�P�h2�xN��g���+CE"�|�Q�W���'4P	�C�!�����l���[�;��ÔG9�&�6'�q���!��J0��b�?ѵSWK��.{-կAt� �U�_�b�?�	hs�YB;��%���!����������AR�8���+�NK��W�LD����E�<6EU��pʕ�������J�Z���ⴞ银S7�>�۩�R���<�bC`��j��ġ��v��u��6�H\�*cp��y
���\'�r�М	LHb��:'>�^ �]{L�"6�5y�U)�]Q*1�Zd��t���i:^�,M|������V.B6��]ڑ
�K�]�,���,�13�ю#+�ve�3�K(�:ф�W+�B���?J��B�w/��b�,Oe-�;+	g�-STU�q�O�&��d�C{SJ�C�����}�1��{rP9��R@Λt��q�(�zm�҆1�Tv*��Ū�8Ex�%j7�9<`� ���d03�X��H����rt��lh��
�.��#��8ZP��;Y���>w�Y�w����S:��|���F�31�x�����j��Y-��Iję���9���H|�:5��d�����9K��Y� WU*�gS{����MK�d|X���	1f�O�M'��m�TAuE{����l��A=��XL[���﫴�J�Nr�Z�X�c�l�W��Ětg��i�ֺö�侼VS����[	E��F���u��&h�T��
l��=�����OG2�MgK�·��J���Xh���y#UI��]����$�~�uʛ2ܢ���k���[��p�3�O��55qj�T�RP�%@�qX�y����+)�,Q
4�*Ô��-:ף���j���L�Z����ȶ�ڒ�}=;�6��8d��O'����P5�o:�kI�F��S����"V!E�(G�Q^�(	Et�{mW�k�^ͤ��!-Z_z6�2C���{V�tʡw%E���Tɪ�Tڨ,םC�g/4q��:/LIL��(����<޴�Y�u(�γO�ff���w~B�Ҽ
)�Y��[:�@�#��5��"��!�^�{����U^=���{u<ݕ�攂��xH>;W��'�!~�.E��4��k�$�V(��,����ŀ�딺�nui�b��^��J3����o�$/6�-�{�{�D�Z"�sx�*�ǐ���Y�4xr]ڢ�N��uh̓�k�� ��-�*V?�w���]�(@�z�D�>]�@-�Bw�ft�8���$�b
ʽԭ8<KA.;�Tq�4���|(G�u�t�A��%	�NM��'x�����iі4Ճ���?�`�\��3[�E%��R����"
3�8N:�E���G8-ar$�֜������H�A�T�ǸAR��Zl� 9�q#6�B	B�Z}O@���u�;�Y�X�S��hK\䵖��bq�{3���MeҲ����0����D��J�����T�E	#�8�*� 0'",��q$ڳ��*E�YR`U��P
2�@hю�\��5�.쫸�"{������B!x�%�]'ލj ���QSRi�=u�pu "��-�?����]�������
�\�9��4�� ���j��VOJ�j���������XP��t��V�T��V��Q bw�ޯZ�u��'�W�����2e"~-�F�co.�S]�U�l4����7vm��L^
Ů�{BOu /Շ�g$�����h"p4���L4��v+�۵���VM�c(�[G���yj 1�)6���s x��)x}��$�����ާy`/F�ր`)��ҍ*�_)3ή+쀱.���u��P���*���4 �u��zڪ�݄=�  �iCCPICC profile  x�}�=H�@�߶�J�8�A�!Hu� *��V�B�Ъ�ɥФ!Iqq\�,V\�uup�G''E)��"�;�{x�{_���
Sͮ1@�,#�L�ܪzEA�C����ωb
���>���y�wݟ�Gɛ�	ĳL7,��MK�Oe%I!>'5�ď\�]~�\t��3�F&=O%�,w0+*�$qLQ5��g]V8oqV+5ֺ'a$��,s�� �X�D�QCX�Ӯ�b"M�	����%��F�T�Br���fab�M�$���m�]�Y���c�n� �g�Jk��`���z[�����u[������I�ɑ����~Fߔ�n��۷�9N��*u#E�^�xwwg���i���&r���h  �iTXtXML:com.adobe.xmp     <?xpacket begin="﻿" id="W5M0MpCehiHzreSzNTczkc9d"?>
<x:xmpmeta xmlns:x="adobe:ns:meta/" x:xmptk="XMP Core 4.4.0-Exiv2">
 <rdf:RDF xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
  <rdf:Description rdf:about=""
    xmlns:xmpMM="http://ns.adobe.com/xap/1.0/mm/"
    xmlns:stEvt="http://ns.adobe.com/xap/1.0/sType/ResourceEvent#"
    xmlns:dc="http://purl.org/dc/elements/1.1/"
    xmlns:GIMP="http://www.gimp.org/xmp/"
    xmlns:tiff="http://ns.adobe.com/tiff/1.0/"
    xmlns:xmp="http://ns.adobe.com/xap/1.0/"
   xmpMM:DocumentID="gimp:docid:gimp:8dd71e5a-ce11-47dd-a14f-eecf8b212dcb"
   xmpMM:InstanceID="xmp.iid:7f854992-fd49-49e9-8c1b-0bee62102bee"
   xmpMM:OriginalDocumentID="xmp.did:8a7c1f6f-84f5-41cc-8534-b5d555713a07"
   dc:Format="image/png"
   GIMP:API="2.0"
   GIMP:Platform="Linux"
   GIMP:TimeStamp="1664948664075237"
   GIMP:Version="2.10.32"
   tiff:Orientation="1"
   xmp:CreatorTool="GIMP 2.10"
   xmp:MetadataDate="2022:10:05T07:44:22+02:00"
   xmp:ModifyDate="2022:10:05T07:44:22+02:00"
   xmp:Rating="0">
   <xmpMM:History>
    <rdf:Seq>
     <rdf:li
      stEvt:action="saved"
      stEvt:changed="/"
      stEvt:instanceID="xmp.iid:a6ed7619-3f5a-4a59-ab7d-df2ed5dfba27"
      stEvt:softwareAgent="Gimp 2.10 (Linux)"
      stEvt:when="2022-10-05T07:44:24+02:00"/>
    </rdf:Seq>
   </xmpMM:History>
  </rdf:Description>
 </rdf:RDF>
</x:xmpmeta>
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                                                                                                    
                           
<?xpacket end="w"?>�	=   bKGD      �C�   	pHYs     ��   tIME�
,]1��  %IDATh�-�I�e�a��}�>�9����׿W�ER�EQ�������2���(�"� �<	#�n`9�D�%V��ռz��O��3`~��,,,|X����ض3<���u���A2`�E���m��Z�lv@k��f�o
��=�ݠ�"Ij��ǔE�(Rt}��"ty�l�Mߵ�����tF��Oq������l���tM���8�����֛�y!�vX�E��$ /;��f�[�єj}ŀ�w%U���l6�nS�l�-.)_����������L��Ĥ�B*���c^�z&�=�Y��X#�>B8��h��$]r��/���6�n��2����w-B����ЁrY�
�hJQ�^�Ko|���=N_P�~L�!�ܓ��;�,̒����\�(�����P�$� �g�I܈θ�ɘ(�p�Ɖ��Cʞ��qL��hF?t�*@s��g*�'H�h�/R��G�`���ĳS�b�P-q�%���l�>�՞���G��_�ar��S��1z�I�1��1U�t#=�.��Q M]��J���xL��ٻ�:Ǣ�D��p��X-�2chr��Cʏ"�0 u�TƸ�Dp�I�nDK��f��Ѭ�T�
��^�z�qvw�~�E1e����fS�!Q�w'��8�	m�����h�c��ȋ-\��+-%�ӳ�k-����Q!P]U�Q�1t%Qz@%'�X
��24;�%n�ج��JpT�+-�w]�p�@r�>��z���q�K�טl�w�r����<M�-�EI0m��F�=�^"1�"��jW+�^;q�E0tN8A]���#.�y���t�;�����ڒD�S<��d��()��%�%w���~��M|�6��	�9i�b�EC�c]ESwx�Jj�y�=T�q�E��4T��6�xzHWWd�{S69�qFSm���o}%y�pWx�� ��0�}�w�o<��y�2�!���eX����3��d�����OcU�a�e�H�ݒx�P�bp1���#�A��1�%I'�� ��ek�����Y#�����H/"�\��S����K�5���`r|I+'x^DS��1��$�@���Ƴ9e1�55�1m�n{�vE����ݾE
�C�J���h{�ԗ |zc9L\�:bpC�8� ��l��a���돱�)����i��""c��m�� �,(��b��9e���]]�Bh��`�,�{Gg�7�q���)Q$�i�5e!6U�e_���ǌ&�X-�����:o��+:�0@�v��G�woP���㤇͸�1&
�vT�{��6�m����sɃ3���H����>�J���;L�EˈR�8:��n�/Zd�´��4Lf3z�R���:���<�����O�9��1bۓ�.Eo16$
S�~�i�V��:��� ;Y �"h7颧����-^<��䘇�+�n�WO�H$������w�\���IÐ����?���nOWW��*��۱��2M=6�g{8$�a�(V�a�C�)V����I���`�Z�������U��V�z�S�1��9��p��0������|��|��ۨ�����-kFu�c&YJ7h��n[�ų� ��d�lu�Q�I$L�w�˽p�@�5N7p:<)4��P�á�����P��U��3��G�s
�3��H����~~���	�Хjz���W��}[QS���ftLr~L'��.κD􆛪���;p6��
?�H/B��=�A���X�Ѵ���1toh�����0����N�߲�������5n��:\!�b�m��%���o�?�o�3��a��K|YQCEd����-�~�Qt3X�f�lz�����C9@[uD������3� �qcОb��'���w({V�i��L�3�o���)���1r%ʄ#":�|w_�&��A��v���� $�� 	0�C�����?p���}B�~�������>�1��W��u<�h]�f0����:z�P�H)p�J�qP���3�_qu����	�u�ȱU����c�9��)�x���}�9���}�$�Jb�`2��B��t���p��q�1�4�tzǿL����3���ݼ��j����o9��i7A{>�����{�U;��`q�IT�o'_�CuO+ǔ��#���/�S�7��~��ǄNO���S�5�nO��q��=�DR�n��_����O�l�������(%s{�$�fۣf0
\��K�BSw<�ʉ&s�ZXT�a�f}K4���4b����.��A�>�}ݢ�9U�S�!�h�bȱ��}�`�)	�%,J�DNOYմZ�����o�F�ſ�gv<?�p�x�8��0��zž8{4!	UY�(��|�ȁ���DTV���W/r��c~��9m0�F��n��[�V9�l�<V��5U�����!/�}���yt<��lN��@�y,W;����pD�p��u��xF:�0B���y�����K �G3\�aЂ�7|���&��5W^_�t������_|�ý��մ��X��7Kf��$Rh���;tSrv��=hz�Y�mZ6�%o�&|��%*�X=����#o�#���{�k����cY\�">��O�������2HG�����4;�^q�P�4a�q4�Q��m����(�2=?�0D5�t�l���fESֈ�Ca���t�(��G0�8�iloȗKD��Г�/QnVl��e�l;�@�ݷ\�l9��NƈO?��6�B&q@<��ː��^�������v�@{DQ̛g/x��W��%;���f��.��2���!	]�D1�$L�����8B��f���g>
��� ��+B����l� ,A���e������7��j�p$A�R��-������^1N<��e�q��ϯ�-ۗ��}Et4b����8��߅(��bM��h��]�b���qi[A������z�Ӿd���q�C��{�(b{�e�wTE^��hF�B5X�c� 9?X|�8:���הu�þ�`�8�F�(vےo�v_~E(N�;����|�G4��5JY��;��z�	S~��iʒ N�5eQ3JB�^�LGD��h-(V���0�/a��&���	i���
��ǟX�@8�� �(�Y,���,bX��jBנ���|�ф(K��2\�b4}I6M������FE	��P��1MUE���p6#N}t�A�Su����lqGs����qG)��>���,�<#$fP���咡�8��duw�'|���{�����p8��p�
��=�M�����i��2�h̓g���&KFd�	���ݍ���p�u7�����#=�8 �h���~}�r[ѵ-=�c�f��0�zȡ�����[?@k\�#K�y����c5gGS<�c�Y�ctבx0
�`	��q
�r��a>͸��3�� ���<��ƕ���	�8�Xc\����U����0N�[-yv]P���E��!M�"���2I<�c�j���Pv��-WR�+�]�J�0�9:�Ph�-K�1�=��qUA����!i���=\��z���~�ǟ\д�n�@��QH���B���uY?������`ľ깾_�X���e��B'TEI���<T�8B����<��	��'_�YRT5y���s�q�r��U'��j�`	}EG]�/��k6�G3��}����X��LQ�>a�N&�|��%ugyu��l��/7�ܔ����-_P�-ٳ7��I��>B-7;� ����(������A	�������.�l�,fsޞ'����DI����̰+,��K֫�8Ѭ��I�!%�-��#/��C|��tp�W�G.�D�勯6�UM^�x▱'}�����l���=Y�PWC�y.��3����?����ٓ�YLy�p�����|J��)Bx��]��;���ܼY�9�8�f	Q������eN����P9()g	��q���m����xM�v(�%NGl�{.]���m�<:9�\�~�aqt���-}��8�0��D<\�!p�IL��(�p}[��	�jCk~�|�W��{�M���~�xH����!���`�@����w�+�c�D�a�J���}�8f�$Q@���]������'��l2A�=��$�������y�7�>!;��Z�1�ӌ���v�e��k0���:��E^ ����(
P���<|����}٠u��zH)��#����������ܬ+�w+�^��%�dJ�V�|��$1�.��4u��$����,I��~}�hjg�d���<�]�q��-��Lb��Y�:�m�r}���O�p��{���8��8K�\A7h�pX�-�����(�����<l���c������w���ߠ��c����8�9=;f��0P��;GD1&�к��z��1D.�����C�yA?��`���[�0"M������1���g���C�;�9pw���Şgo��Q@�4]O6�y�/1����|���PA��L��0�X��;
\�?��g_�mz�$�jS�x!�͒]YR�0M�$�BQ����h��!�����)�'X���9c�}tg�_V�~G��NCgz<��ۛ%8�ӓc����b�l�!U�R۲�oJ�z�2CO��X�s�$��>�h.1q]�h��K��Ƿo֌��a�v����e�Ǽ�\?��bq�b���?���Vxa�� ̎0����Jwǡ�.z�T�
%4
�]3�	���%�5Y�3I"�݆ݮ@*�n�&L\�PU���i��[�?���S��w�f�0���FI��hƫ/�(��|��v���U�sxx��I���.���,K8<�㊎��>��� ��`�Q�5�m�6}�0�0k�,��o�<�.�R�{��Q���@X��Piħ?���<;���;hF����-U�0�bʦ#�.t-����߮��'�賟r��7���[��D��t6 L�tՎ�= �¤D���'K�F���3��Lz4�v�=��Hm�������(��b��}�ʀ��x�s�<�u�lv,����g���U�?h��%Mb��ء��ֲ������:!K]]�b�q���u�\�k��c��M��e�鹿^��V!����_P=Ջ���A� ���h<Ÿ.E�#\�8M�t]T�D�~�f�!��S	C70�>nS!�@�|�c��x��љ�4������k<�Ҩ�um���l9+"y����q`H����e߷��N�,�4m��oWt_w��Q����� ��nJ\ �LY/��0$�<�1��n�N��{ƎFJ��먍�7#%�r��m;0�O���3�rW|��C˧��d8nD�M����"榨��˖��q=����X���m�M�A�qprF�[s[�T�����٘���[~�ǿ���7�b�
�8�}�
��̉�c�^@hG�����X�لq��������ے�����(ѻ>wuL}c�<X߭����nG<>&>8D�ܽ���o���mq<���8�Lȫ����s�M��d�����՘����@h�`�h_� 4N?hT�=Ӿ%�.H�3�n�`5��~��=AMxuuKY7l���(	�!Q ��BZ#�4\-���B*�nhۖ��5���,
f��8B��DH��GL������o�����쫆Mk�_���ugh���@FC��޽&�D(�ہ��{���!���M����::b������{�o�9qc���$`~rJ�*�nVlp��{l70_Q9��^�B�E����l<!��tˎ�s�r=�N�f)�xD��<�pw{�r����.CY0:>e��+��М�K����z�b�ۃ�&����>>긫z���_�-����p�rU��ؾ�,J�8a������{Ů��B�!�m����xsu�#B:L'�?	�O�y��ˇ���~��=TēCF��ѕ{|GQ�p���i͞�mhX�=�#~��)��&�v%�[��oys[��k
m�ӌ/~�W)޿<�x�Q�o�CK�~���ɔ���������B�5}ד�1ˇ{���̦(10�=~R7�1��-�lZ��#'36�%�
�~X�A�$�R/d:��2��x�,7}M��m[&I��$$�������*��������ӉT���m1�$鈢��h�j�b2���9ҁ���[�d<�n.]�� (���l(*5    IEND�B`�           ECFG      application/config/name         Visualizations     application/run/main_scene(         res://productions/warshall.tscn    application/config/icon         res://icon.png     display/window/size/width      �     display/window/size/height      8     global/alias          +   gui/common/drop_mouse_on_gui_input_disabled            input/pan_click�              deadzone      ?      events              InputEventMouseButton         resource_local_to_scene           resource_name             device     ����   alt           shift             control           meta          command           button_mask           position              global_position               factor       �?   button_index         pressed           doubleclick           script         input/zoom_in�              deadzone      ?      events              InputEventMouseButton         resource_local_to_scene           resource_name             device     ����   alt           shift             control           meta          command           button_mask           position              global_position               factor       �?   button_index         pressed           doubleclick           script         input/zoom_out�              deadzone      ?      events              InputEventMouseButton         resource_local_to_scene           resource_name             device     ����   alt           shift             control           meta          command           button_mask           position              global_position               factor       �?   button_index         pressed           doubleclick           script         input/recenter�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode             unicode           echo          script         input/reset_physics�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode           unicode           echo          script         input/increase_con_attr�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      Q      unicode           echo          script         input/increase_uncon_attr�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      W      unicode           echo          script         input/decrease_con_attr�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      A      unicode           echo          script         input/decrease_uncon_attr�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode      S      unicode           echo          script         input/reset�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode           unicode           echo          script      
   input/quit�              deadzone      ?      events              InputEventKey         resource_local_to_scene           resource_name             device            alt           shift             control           meta          command           pressed           scancode          physical_scancode           unicode           echo          script      )   physics/common/enable_pause_aware_picking         )   rendering/environment/default_environment          res://default_env.tres          