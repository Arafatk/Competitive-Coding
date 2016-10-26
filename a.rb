require 'github/markup'
file = 'b.markdown'
GitHub::Markup.render(file, File.read(file))
