import App from './App.svelte';
import { entrypoints } from 'uxp';

var app = new App({
  target: document.body,
});

entrypoints.setup({
  plugin: {
    create(plugin: any) {
      console.log('Plugin created successfully!', plugin);
    },
    panels: {
      app: app,
    },
  },
});
