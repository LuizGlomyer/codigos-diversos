--skip-download             Do not download the video
--newline                   Output progress bar as new lines
-q, --quiet                 Activate quiet mode
--playlist-start NUMERO     limite inferior da playlist
--playlist-end NUMERO       limite superior da playlist, vai baixar os videos desse intervalo
--write-description         Write video description to a .description file
--write-info-json           Write video metadata to a .info.json file
--write-annotations         Write video annotations to a .annotations.xml file
--write-thumbnail           Write thumbnail image to disk
--write-all-thumbnails      Write all thumbnail image formats to disk
--write-sub                 Write subtitle file
--list-thumbnails           Simulate and list all available thumbnail formats
-g, --get-url               Simulate, quiet but print URL
-e, --get-title             Simulate, quiet but print title
--get-id                    Simulate, quiet but print id
--get-thumbnail             Simulate, quiet but print thumbnail URL
--get-description           Simulate, quiet but print video description
--get-duration              Simulate, quiet but print video length
--get-filename              Simulate, quiet but print output filename
--get-format                Simulate, quiet but print output format
-j, --dump-json             Simulate, quiet but print JSON information. See the "OUTPUT TEMPLATE" for a description of available keys.




-o : para a filename na saída
modelo: -o "%(title)s.%(ext)s" nome do video e extensão
        -o "~/Downloads/%(uploader)s/%(title)s.%(ext)s" coloca os arquivos em uma nova pasta com o nome do canal, aplicando as configs acima

id (string): Video identifier
title (string): Video title
url (string): Video URL
ext (string): Video filename extension
alt_title (string): A secondary title of the video
display_id (string): An alternative identifier for the video
uploader (string): Full name of the video uploader


